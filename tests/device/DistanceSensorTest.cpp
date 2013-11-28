#include "CppUTest/TestHarness.h"

#include "MockDistSensor.h"

TEST_GROUP(DistanceSensor)
{
    MockDistSensor* sensor;

    void setup()
    {
        sensor = new MockDistSensor();
    }

    void teardown()
    {
        delete sensor;
    }
};

TEST(DistanceSensor, Init)
{
    sensor->init();

    LONGS_EQUAL(MockDistSensor::INVALID_DISTANCE, sensor->getFrontDistance());
}

TEST(DistanceSensor, Step)
{
    sensor->init();

    sensor->setDummyDistance(10);

    sensor->step();

    LONGS_EQUAL(10, sensor->getFrontDistance());
}

TEST(DistanceSensor, NoStep)
{
    sensor->init();

    sensor->setDummyDistance(10);

    LONGS_EQUAL(MockDistSensor::INVALID_DISTANCE, sensor->getFrontDistance());
}

