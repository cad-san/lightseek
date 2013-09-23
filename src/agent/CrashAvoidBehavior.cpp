#include "CrashAvoidBehavior.h"

static const int THRESHOLD_DIST = 50;

CrashAvoidBehavior::CrashAvoidBehavior(const unsigned int behavior_id,
                                       const DistSensorPtr& sensor_ptr,const ActionPtr& action_ptr)
    : Behavior(behavior_id), sensor(sensor_ptr), action(action_ptr)
{
    sensed_dist = DistSensor::INVALID_DISTANCE;
}

CrashAvoidBehavior::~CrashAvoidBehavior()
{
}

void CrashAvoidBehavior::init()
{
    sensed_dist = DistSensor::INVALID_DISTANCE;
}

void CrashAvoidBehavior::sensing()
{
    sensed_dist = sensor->getDistance();
}

void CrashAvoidBehavior::perform()
{
    if(!isActive())
        return;

    action->rotate(90 * (1 - sensed_dist / THRESHOLD_DIST) );
}

const bool CrashAvoidBehavior::isActive() const
{
    return (sensed_dist >= 0 && sensed_dist < THRESHOLD_DIST);
}
