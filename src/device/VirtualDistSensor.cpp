#include "VirtualDistSensor.h"

VirtualDistSensor::VirtualDistSensor(const RobotPtr& robot) : robot(robot)
{
    this->distance = INVALID_DISTANCE;
}

VirtualDistSensor::~VirtualDistSensor()
{
}

void VirtualDistSensor::init()
{
    this->distance = INVALID_DISTANCE;

    if(robot)
        robot->init();
}

void VirtualDistSensor::step()
{
    if(robot)
        distance = robot->getDistance();
}

int VirtualDistSensor::getDistance() const
{
    return distance;
}

