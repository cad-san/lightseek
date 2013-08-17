#ifndef D_VIRTUAL_DIST_SENSOR_H
#define D_VIRTUAL_DIST_SENSOR_H

#include "DistSensor.h"

class VirtualDistSensor : public DistSensor
{
public:
    VirtualDistSensor();
    virtual ~VirtualDistSensor();

    void init();
    void step();

    int getDistance() const;
};

#endif

