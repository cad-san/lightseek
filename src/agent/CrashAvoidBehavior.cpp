#include "CrashAvoidBehavior.h"

static const int THRESHOLD_DIST = 50;

CrashAvoidBehavior::CrashAvoidBehavior(const unsigned int behavior_id,
                                       const DistSensorPtr& sensor_ptr,const ActionPtr& action_ptr)
    : Behavior(behavior_id), sensor_(sensor_ptr), action_(action_ptr)
{
    sensed_dist_ = DistSensor::INVALID_DISTANCE;
    threshold_dist_ = THRESHOLD_DIST;
    rotate_direct_ = ROTATE_RIGHT;
}

CrashAvoidBehavior::~CrashAvoidBehavior()
{
}

void CrashAvoidBehavior::init()
{
    sensed_dist_ = DistSensor::INVALID_DISTANCE;
    rotate_direct_ = ROTATE_RIGHT;
}

void CrashAvoidBehavior::sensing()
{
    sensed_dist_ = sensor_->getFrontDistance();

    int l_dist = sensor_->getLeftSideDistance();
    int r_dist = sensor_->getRightSideDistance();
    rotate_direct_ = (l_dist > r_dist) ? ROTATE_LEFT : ROTATE_RIGHT;
}

void CrashAvoidBehavior::perform()
{
    if(!isActive())
        return;

    double ratio = 1.0 - static_cast<double>(sensed_dist_) / threshold_dist_;
    int angle =  rotate_direct_ * static_cast<int>(90.0 * ratio);
    action_->rotate(angle);
}

bool CrashAvoidBehavior::isActive() const
{
    return (sensed_dist_ >= 0 && sensed_dist_ < threshold_dist_);
}

void CrashAvoidBehavior::setThreshold(int distance)
{
    threshold_dist_ = distance;
}
