#ifndef D_VIRTUAL_ACTION_H
#define D_VIRTUAL_ACTION_H

#include "Action.h"
#include "Robot.h"

class VirtualAction : public Action
{
private:
    RobotPtr robot_;

public:
    VirtualAction(const RobotPtr& robot);
    virtual ~VirtualAction();

    virtual bool moveFront(const int speed);
    virtual bool rotate(const int angle);
};

#endif
