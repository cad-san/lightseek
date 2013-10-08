#ifndef D_DIST_SENSOR_H
#define D_DIST_SENSOR_H

#include "SensorController.h"

class DistSensor : public SensorController
{
public:
    static const int INVALID_DISTANCE = -1;

    DistSensor() {}
    virtual ~DistSensor() {}
    virtual int getDistance() const = 0;
};

typedef boost::shared_ptr<DistSensor> DistSensorPtr;

#endif

