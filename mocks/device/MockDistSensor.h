#ifndef D_MOCK_DIST_SENSOR_H
#define D_MOCK_DIST_SENSOR_H
#include "DistSensor.h"

class MockDistSensor : public DistSensor
{
private:
    int curr_dist;
    int dummy_dist;

public:
    MockDistSensor()
    {
        curr_dist = INVALID_DISTANCE;
        dummy_dist = INVALID_DISTANCE;
    }

    ~MockDistSensor()
    {
    }

    void init()
    {
        curr_dist = INVALID_DISTANCE;
        dummy_dist = INVALID_DISTANCE;
    }

    void step()
    {
        curr_dist = dummy_dist;
    }

    int getDistance() const
    {
        return curr_dist;
    }

    void setDummyDistance(int dummy_dist)
    {
        this->dummy_dist = dummy_dist;
    }
};

#endif

