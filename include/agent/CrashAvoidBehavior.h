#ifndef D_CRASH_AVOID_BEHAVIOR_H
#define D_CRASH_AVOID_BEHAVIOR_H

#include "Behavior.h"
#include "Action.h"
#include "DistSensor.h"

class CrashAvoidBehavior : public Behavior
{
private:
    bool active_flag;
    DistSensorPtr sensor;
    ActionPtr action;
public:
    CrashAvoidBehavior(const DistSensorPtr& sensor_ptr,
                       const ActionPtr& action_ptr);
    virtual ~CrashAvoidBehavior();

    virtual void init();
    virtual void sensing();
    virtual void perform();

    virtual const bool isActive() const;
};

#endif
