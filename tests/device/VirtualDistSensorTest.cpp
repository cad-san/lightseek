#include "CppUTest/TestHarness.h"

#include "Robot.h"
#include "MockWorld.h"
#include "VirtualDistSensor.h"

#include <boost/make_shared.hpp>

TEST_GROUP(VirtualDistSensor)
{
    MockWorldPtr worldPtr;
    RobotPtr robotPtr;
    VirtualDistSensor* sensor;

    void setup()
    {
        worldPtr = boost::make_shared<MockWorld>();
        robotPtr = boost::make_shared<Robot>(worldPtr);
        sensor = new VirtualDistSensor(robotPtr);

        sensor->init();
    }

    void teardown()
    {
        mock().clear();
        delete sensor;
    }
};

TEST(VirtualDistSensor, Init)
{
    LONGS_EQUAL(VirtualDistSensor::INVALID_DISTANCE, sensor->getFrontDistance());
}

TEST(VirtualDistSensor, Step)
{
    // Robot初期化
    robotPtr->setPosition(50, 100);
    robotPtr->setAngle(0);

    // MockWorldを設定
    worldPtr->setExpectionOfGetDistance(50, 100,  0);
    worldPtr->setExpectionOfGetDistance(50, 100, 90);
    worldPtr->setExpectionOfGetDistance(50, 100,-90);
    worldPtr->setDummyDistance(150);

    // 処理を実行
    sensor->step();
    mock().checkExpectations();

    LONGS_EQUAL(150, sensor->getFrontDistance());
    LONGS_EQUAL(150, sensor->getLeftSideDistance());
    LONGS_EQUAL(150, sensor->getRightSideDistance());
}
