#include "GoStraightBehavior.h"

static const int THRESHOLD_DIST = 50;

GoStraightBehavior::GoStraightBehavior(const unsigned int behavior_id,
                                       const DistSensorPtr& sensor_ptr, const ActionPtr& action_ptr)
    : Behavior(behavior_id), sensor(sensor_ptr), action(action_ptr)
{
    sensed_dist = DistSensor::INVALID_DISTANCE;
}

GoStraightBehavior::~GoStraightBehavior()
{
}

void GoStraightBehavior::init()
{
    sensed_dist = DistSensor::INVALID_DISTANCE;
}

void GoStraightBehavior::sensing()
{
    sensed_dist = sensor->getDistance();
    sensed_dist = sensed_dist < 100 ? sensed_dist : 100;
}

void GoStraightBehavior::perform()
{
    if(!isActive())
        return;

    int speed = (sensed_dist - THRESHOLD_DIST) / 2;

    action->moveFront(speed);
}

const bool GoStraightBehavior::isActive() const
{
    return (sensed_dist >= THRESHOLD_DIST);
}
