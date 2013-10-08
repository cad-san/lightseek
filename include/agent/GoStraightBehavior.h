#ifndef D_GO_STRAIGHT_BEHAVIOR_H
#define D_GO_STRAIGHT_BEHAVIOR_H

#include "Behavior.h"
#include "Action.h"
#include "DistSensor.h"

class GoStraightBehavior : public Behavior
{
private:
    int sensed_dist_;
    DistSensorPtr sensor_;
    ActionPtr action_;
public:
    GoStraightBehavior(const unsigned int behavior_id,
                       const DistSensorPtr& sensor_ptr, const ActionPtr& action_ptr);
    virtual ~GoStraightBehavior();

    virtual void init();
    virtual void sensing();
    virtual void perform();

    virtual bool isActive() const;
};

#endif
