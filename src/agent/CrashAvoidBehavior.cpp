#include "CrashAvoidBehavior.h"

CrashAvoidBehavior::CrashAvoidBehavior(const DistSensorPtr& sensor_ptr, const ActionPtr& action_ptr)
    : sensor(sensor_ptr), action(action_ptr)
{
    active_flag = false;
}

CrashAvoidBehavior::~CrashAvoidBehavior()
{
}

void CrashAvoidBehavior::init()
{
    active_flag = false;
}

void CrashAvoidBehavior::sensing()
{
}

void CrashAvoidBehavior::perform()
{
}

const bool CrashAvoidBehavior::isActive() const
{
    return active_flag;
}
