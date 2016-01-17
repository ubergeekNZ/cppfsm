#include "AppFSM.h"
#include "MockState.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std; 

using ::testing::_;
using ::testing::InSequence;
using ::testing::Return;

#define MAX_MOCK_STATES     (10)
#define MAX_TEST_ITERATIONS     (20)

class AppFSMTests : public ::testing::Test
{
protected:
    MockState mock_state[MAX_MOCK_STATES];
    uint32_t current_state;

    AppFSM fsm;

    AppFSMTests() {}

    virtual void SetUp()
    {
       for (int i =0 ; i< MAX_MOCK_STATES; i++)
       {
          fsm.AddState(mock_state[i], i);
       }
       current_state = 0;
       fsm.InitState(mock_state[current_state]);
    }
};

TEST_F(AppFSMTests, TestFSM)
{
    sEvent event;

    event.id = 0;

    for (int i = 0; i < MAX_TEST_ITERATIONS; i++)
    {
        EXPECT_CALL(mock_state[current_state], OnHandle(_));
        fsm.ScheduleEvent(event);

        EXPECT_CALL(mock_state[current_state], Update());
        fsm.Update();

        EXPECT_CALL(mock_state[current_state], OnExit());
        
        // Change state
        current_state = rand() % 10;

        EXPECT_CALL(mock_state[current_state], OnEntry());

        fsm.SetState(current_state);
    }

    // App FSM dies
    EXPECT_CALL(mock_state[current_state], OnExit());
}
