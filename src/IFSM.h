#ifndef IFSM_H
#define IFSM_H

#include "Events.h"
#include "IState.h"


class IFSM
{
public:
    virtual ~IFSM() {}
    virtual void InitState(IState& state) = 0;
    virtual void AddState(IState& state, uint32_t stateID) = 0;
    virtual void SetState(uint32_t stateID) = 0;
    virtual void ScheduleEvent(sEvent& evt) = 0; 
    virtual bool IsRunning() = 0;
    virtual void Update() = 0;
};

#endif

