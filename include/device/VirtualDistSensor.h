#ifndef D_VIRTUAL_DIST_SENSOR_H
#define D_VIRTUAL_DIST_SENSOR_H

#include "DistSensor.h"
#include "Robot.h"

class VirtualDistSensor : public DistSensor
{
private:
    RobotPtr robot;
    int distance;

public:
    VirtualDistSensor(const RobotPtr& robot);
    virtual ~VirtualDistSensor();

    void init();
    void step();

    int getDistance() const;
};

#endif

