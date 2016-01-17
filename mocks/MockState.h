#ifndef MOCKSTATE_H_
#define MOCKSTATE_H_

#include "gmock/gmock.h"
#include "IState.h"
#include "Events.h"

class MockState : public IState
{
public:
    MOCK_METHOD1(OnHandle, void(sEvent& evt));
    MOCK_METHOD0(Update, void());
    MOCK_METHOD0(OnEntry, void());
    MOCK_METHOD0(OnExit, void());
    MOCK_METHOD0(GetStateID, uint32_t());
};

#endif // MOCKSTATE_H_
