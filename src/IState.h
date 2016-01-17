#ifndef ISTATE_H
#define ISTATE_H

class IState
{
public:
    virtual ~IState() {}
    virtual void OnHandle(sEvent& evt) = 0;
    virtual void Update() = 0;
    virtual void OnEntry() = 0;
    virtual void OnExit() = 0;
    virtual uint32_t GetStateID() = 0;
};

#endif
