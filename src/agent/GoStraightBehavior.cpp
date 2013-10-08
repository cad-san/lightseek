#include "GoStraightBehavior.h"

static const int THRESHOLD_DIST = 50;

GoStraightBehavior::GoStraightBehavior(const unsigned int behavior_id,
                                       const DistSensorPtr& sensor_ptr, const ActionPtr& action_ptr)
    : Behavior(behavior_id), sensor_(sensor_ptr), action_(action_ptr)
{
    sensed_dist_ = DistSensor::INVALID_DISTANCE;
}

GoStraightBehavior::~GoStraightBehavior()
{
}

void GoStraightBehavior::init()
{
    sensed_dist_ = DistSensor::INVALID_DISTANCE;
}

void GoStraightBehavior::sensing()
{
    sensed_dist_ = sensor_->getDistance();
    sensed_dist_ = sensed_dist_ < 100 ? sensed_dist_ : 100;
}

void GoStraightBehavior::perform()
{
    if(!isActive())
        return;

    int speed = (sensed_dist_ - THRESHOLD_DIST) / 2;

    action_->moveFront(speed);
}

bool GoStraightBehavior::isActive() const
{
    return (sensed_dist_ >= THRESHOLD_DIST);
}
