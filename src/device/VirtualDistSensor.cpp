#include "VirtualDistSensor.h"

VirtualDistSensor::VirtualDistSensor(const RobotPtr& robot) : robot_(robot)
{
    this->distance_ = INVALID_DISTANCE;
}

VirtualDistSensor::~VirtualDistSensor()
{
}

void VirtualDistSensor::init()
{
    lock lk(sync_mutex_);

    this->distance_ = INVALID_DISTANCE;

    if(robot_)
        robot_->init();
}

void VirtualDistSensor::step()
{
    lock lk(sync_mutex_);
    if(robot_)
        distance_ = robot_->getFrontDistance();
}

int VirtualDistSensor::getDistance() const
{
    lock lk(sync_mutex_);
    return distance_;
}

