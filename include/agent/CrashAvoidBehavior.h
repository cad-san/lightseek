#ifndef D_CRASH_AVOID_BEHAVIOR_H
#define D_CRASH_AVOID_BEHAVIOR_H

#include "Behavior.h"
#include "Action.h"
#include "DistSensor.h"

class CrashAvoidBehavior : public Behavior
{
private:
    typedef enum {
        ROTATE_RIGHT = 1,
        ROTATE_LEFT  = -1
    } RotateDirect;

    int sensed_dist_;
    int threshold_dist_;

    RotateDirect rotate_direct_;

    DistSensorPtr sensor_;
    ActionPtr action_;

    RotateDirect calcRotateDirection(void) const;

public:
    CrashAvoidBehavior(const unsigned int behavior_id,
                       const DistSensorPtr& sensor_ptr, const ActionPtr& action_ptr);
    virtual ~CrashAvoidBehavior();

    virtual void init();
    virtual void sensing();
    virtual void perform();

    virtual bool isActive() const;

    void setThreshold(int distance);
};

#endif
