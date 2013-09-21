#include "CrashAvoidBehavior.h"

static const int THRESHOLD_DIST = 50;

CrashAvoidBehavior::CrashAvoidBehavior(const DistSensorPtr& sensor_ptr, const ActionPtr& action_ptr)
    : sensor(sensor_ptr), action(action_ptr)
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
}

const bool CrashAvoidBehavior::isActive() const
{
    return (sensed_dist >= 0 && sensed_dist < THRESHOLD_DIST);
}
