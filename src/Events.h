#ifndef EVENTS_H
#define EVENTS_H

#include <stdint.h>
#include <string.h>

enum eEvent
{
    EVT_IDLE = 0,
    EVT_STATE,
};

struct sEvent
{
    uint32_t id;
    char* data;

    bool operator==(const sEvent &rhs) {
        if (memcmp(this,&rhs,sizeof(*this)))
            return false;
        else return true;
    }
};

#endif