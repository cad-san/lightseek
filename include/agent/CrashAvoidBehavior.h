#ifndef D_CRASH_AVOID_BEHAVIOR_H
#define D_CRASH_AVOID_BEHAVIOR_H

#include "Behavior.h"
#include "Action.h"
#include "DistSensor.h"

class CrashAvoidBehavior : public Behavior
{
private:
    int sensed_dist;
    DistSensorPtr sensor;
    ActionPtr action;
public:
    CrashAvoidBehavior(const unsigned int behavior_id,
                       const DistSensorPtr& sensor_ptr, const ActionPtr& action_ptr);
    virtual ~CrashAvoidBehavior();

    virtual void init();
    virtual void sensing();
    virtual void perform();

    virtual bool isActive() const;
};

#endif
