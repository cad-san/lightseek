#ifndef D_MOCK_DIST_SENSOR_H
#define D_MOCK_DIST_SENSOR_H

#include "DistSensor.h"
#include "CppUTestExt/MockSupport.h"

class MockDistSensor : public DistSensor
{
public:
    MockDistSensor() {}

    ~MockDistSensor() {}

    void init()
    {
        mock("MockDistSensor").actualCall("init");
    }

    void step()
    {
        mock("MockDistSensor").actualCall("step");
    }

    int getFrontDistance() const
    {
        mock("MockDistSensor")
            .actualCall("GetFrontDistance");
        return mock("MockDistSensor").intReturnValue();
    }

    int getLeftSideDistance() const
    {
        mock("MockDistSensor")
            .actualCall("GetLeftSideDistance");
        return mock("MockDistSensor").intReturnValue();
    }

    int getRightSideDistance() const
    {
        mock("MockDistSensor")
            .actualCall("GetRightSideDistance");

        return mock("MockDistSensor").intReturnValue();
    }

    void expectCallInit()
    {
        mock("MockDistSensor")
            .expectOneCall("init");
    }

    void expectCallStep()
    {
        mock("MockDistSensor")
            .expectOneCall("step");
    }

    void setExpectionOfGetFrontDist(int dummy_dist)
    {
        mock("MockDistSensor")
            .expectOneCall("GetFrontDistance")
            .andReturnValue(dummy_dist);
    }

    void setExpectionOfGetLeftSideDist(int dummy_dist)
    {
        mock("MockDistSensor")
            .expectOneCall("GetLeftSideDistance")
            .andReturnValue(dummy_dist);
    }

    void setExpectionOfGetRightSideDist(int dummy_dist)
    {
        mock("MockDistSensor")
            .expectOneCall("GetRightSideDistance")
            .andReturnValue(dummy_dist);
    }

    void setExpectDistance(int front, int left, int right)
    {
        setExpectionOfGetFrontDist(front);
        setExpectionOfGetLeftSideDist(left);
        setExpectionOfGetRightSideDist(right);
    }
};

typedef boost::shared_ptr<MockDistSensor> MockDistSensorPtr;

#endif

