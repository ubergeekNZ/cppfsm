#ifndef APPFSM_H
#define APPFSM_H
 
#include "Events.h"
#include "List.h"
#include "IFSM.h"

#define MAX_STATES			(10)

typedef struct 
{
	IState* state;
	uint32_t stateID;
}StateObject;

class AppFSM : public IFSM
{
	List<StateObject> *m_stateList;

	// AppFSM(const AppFSM&);
	// AppFSM& operator=(const AppFSM&);

	IState* m_pCurrState;
	bool m_running;
public: 
	// TODO  add the class
	AppFSM();
	~AppFSM();
	void ScheduleEvent(sEvent& evt);
	void AddState(IState& state, uint32_t stateID);
	void InitState(IState& state);
	void SetState(uint32_t stateID);
	bool IsRunning();
	void Update();
};

#endif