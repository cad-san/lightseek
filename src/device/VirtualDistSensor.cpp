#include "VirtualDistSensor.h"

VirtualDistSensor::VirtualDistSensor(const RobotPtr& robot) : robot_(robot)
{
    this->front_dist_ = INVALID_DISTANCE;
    this->right_dist_ = INVALID_DISTANCE;
    this->left_dist_ = INVALID_DISTANCE;
}

VirtualDistSensor::~VirtualDistSensor()
{
}

void VirtualDistSensor::init()
{
    lock lk(sync_mutex_);

    this->front_dist_ = INVALID_DISTANCE;
    this->right_dist_ = INVALID_DISTANCE;
    this->left_dist_ = INVALID_DISTANCE;

    if(robot_)
        robot_->init();
}

void VirtualDistSensor::step()
{
    lock lk(sync_mutex_);
    if(robot_)
    {
        front_dist_ = robot_->getFrontDistance();
        left_dist_  = robot_->getLeftSideDistance();
        right_dist_ = robot_->getRightSideDistance();
    }
}

int VirtualDistSensor::getFrontDistance() const
{
    lock lk(sync_mutex_);
    return front_dist_;
}

int VirtualDistSensor::getLeftSideDistance() const
{
    lock lk(sync_mutex_);
    return left_dist_;
}

int VirtualDistSensor::getRightSideDistance() const
{
    lock lk(sync_mutex_);
    return right_dist_;
}
