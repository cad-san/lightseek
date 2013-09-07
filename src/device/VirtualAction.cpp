#include "VirtualAction.h"
#include "Geometry.h"

VirtualAction::VirtualAction(const RobotPtr& robot)
    : robot(robot)
{
}

VirtualAction::~VirtualAction()
{
}

bool VirtualAction::moveFront(const int speed)
{
    return robot->moveFront(speed);
}

bool VirtualAction::rotate(const int angle)
{
    return robot->rotate(angle);
}
