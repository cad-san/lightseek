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
    lock lk(sync_mutex);

    this->distance = INVALID_DISTANCE;

    if(robot)
        robot->init();
}

void VirtualDistSensor::step()
{
    lock lk(sync_mutex);
    if(robot)
        distance = robot->getDistance();
}

int VirtualDistSensor::getDistance() const
{
    lock lk(sync_mutex);
    return distance;
}

