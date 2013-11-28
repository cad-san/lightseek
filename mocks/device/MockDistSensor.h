#ifndef D_MOCK_DIST_SENSOR_H
#define D_MOCK_DIST_SENSOR_H
#include "DistSensor.h"

class MockDistSensor : public DistSensor
{
private:
    int curr_dist_;
    int dummy_dist_;

public:
    MockDistSensor()
    {
        curr_dist_ = INVALID_DISTANCE;
        dummy_dist_ = INVALID_DISTANCE;
    }

    ~MockDistSensor()
    {
    }

    void init()
    {
        curr_dist_ = INVALID_DISTANCE;
        dummy_dist_ = INVALID_DISTANCE;
    }

    void step()
    {
        curr_dist_ = dummy_dist_;
    }

    int getFrontDistance() const
    {
        return curr_dist_;
    }

    void setDummyDistance(int dummy_dist)
    {
        this->dummy_dist_ = dummy_dist;
    }
};

typedef boost::shared_ptr<MockDistSensor> MockDistSensorPtr;

#endif

