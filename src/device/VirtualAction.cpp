#include "VirtualAction.h"
#include "Geometry.h"

VirtualAction::VirtualAction(const RobotPtr& robot)
    : robot_(robot)
{
}

VirtualAction::~VirtualAction()
{
}

bool VirtualAction::moveFront(const int speed)
{
    return robot_->moveFront(speed);
}

bool VirtualAction::rotate(const int angle)
{
    return robot_->rotate(angle);
}
