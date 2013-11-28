#include "VirtualDistSensor.h"

VirtualDistSensor::VirtualDistSensor(const RobotPtr& robot) : robot_(robot)
{
    this->front_dist_ = INVALID_DISTANCE;
}

VirtualDistSensor::~VirtualDistSensor()
{
}

void VirtualDistSensor::init()
{
    lock lk(sync_mutex_);

    this->front_dist_ = INVALID_DISTANCE;

    if(robot_)
        robot_->init();
}

void VirtualDistSensor::step()
{
    lock lk(sync_mutex_);
    if(robot_)
        front_dist_ = robot_->getFrontDistance();
}

int VirtualDistSensor::getFrontDistance() const
{
    lock lk(sync_mutex_);
    return front_dist_;
}

