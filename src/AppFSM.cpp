#include "AppFSM.h"
#include "States.h"

AppFSM::AppFSM() : 
 m_pCurrState(0)
{
    m_stateList = new List<StateObject>(MAX_STATES);
    m_running = true;
}
 
AppFSM::~AppFSM()
{
    if(m_pCurrState)
    {
        m_pCurrState->OnExit();
    }
 
    m_pCurrState = 0;
}

void AppFSM::InitState(IState& state)
{
    m_pCurrState = &state;
    m_pCurrState->OnEntry();
}
 
void AppFSM::ScheduleEvent(sEvent& evt)
{
    m_pCurrState->OnHandle(evt);
}

void AppFSM::AddState(IState& state, uint32_t stateID)
{
    StateObject newState = {&state, stateID};
    m_stateList->push(newState);
}
 
void AppFSM::SetState(uint32_t stateID)
{
    if(m_pCurrState)
    {
        m_pCurrState->OnExit();
    }

    // Find the state in the list
    for (uint32_t index = 0; index < m_stateList->sizeOfList(); index++)
    {
        if (m_stateList->peekElement(index).stateID == stateID)
        {
            m_pCurrState = m_stateList->peekElement(index).state;
            break;
        }
    }

    m_pCurrState->OnEntry();
}

bool AppFSM::IsRunning()
{
    return m_running;
}

void AppFSM::Update()
{
    m_pCurrState->Update();
}
