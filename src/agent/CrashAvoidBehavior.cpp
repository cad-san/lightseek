#include "CrashAvoidBehavior.h"

static const int THRESHOLD_DIST = 50;

CrashAvoidBehavior::CrashAvoidBehavior(const unsigned int behavior_id,
                                       const DistSensorPtr& sensor_ptr,const ActionPtr& action_ptr)
    : Behavior(behavior_id), sensor_(sensor_ptr), action_(action_ptr)
{
    sensed_dist_ = DistSensor::INVALID_DISTANCE;
    threshold_dist_ = THRESHOLD_DIST;
}

CrashAvoidBehavior::~CrashAvoidBehavior()
{
}

void CrashAvoidBehavior::init()
{
    sensed_dist_ = DistSensor::INVALID_DISTANCE;
}

void CrashAvoidBehavior::sensing()
{
    sensed_dist_ = sensor_->getFrontDistance();
}

void CrashAvoidBehavior::perform()
{
    if(!isActive())
        return;

    double ratio = 1.0 - static_cast<double>(sensed_dist_) / threshold_dist_;
    action_->rotate(static_cast<int>(90.0 * ratio));
}

bool CrashAvoidBehavior::isActive() const
{
    return (sensed_dist_ >= 0 && sensed_dist_ < threshold_dist_);
}

void CrashAvoidBehavior::setThreshold(int distance)
{
    threshold_dist_ = distance;
}
