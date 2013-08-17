#include "CppUTest/TestHarness.h"

#include "VirtualDistSensor.h"

TEST_GROUP(VirtualDistSensor)
{
    VirtualDistSensor* sensor;

    void setup()
    {
        sensor = new VirtualDistSensor();
    }

    void teardown()
    {
        delete sensor;
    }
};

TEST(VirtualDistSensor, Init)
{
    sensor->init();

    LONGS_EQUAL(VirtualDistSensor::INVALID_DISTANCE, sensor->getDistance());
}
