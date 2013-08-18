#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "Robot.h"
#include "MockWorld.h"

TEST_GROUP(Robot)
{
    MockWorldPtr worldPtr;
    Robot* robot;

    void setup()
    {
        worldPtr = MockWorldPtr(new MockWorld());
        robot = new Robot(worldPtr);
    }

    void teardown()
    {
        mock().clear();
        delete robot;
    }
};

TEST(Robot, Init)
{
    int x, y;
    double angle;

    robot->getPosition(&x,&y);
    LONGS_EQUAL(World::INVALID_COORD, x);
    LONGS_EQUAL(World::INVALID_COORD, y);

    robot->getAngle(&angle);
    DOUBLES_EQUAL(0.0, angle, 0.0);
}

TEST(Robot, SetPosition)
{
    int x, y;
    double angle;

    robot->setPosition(50, 100);
    robot->setAngle(1.0);

    robot->getPosition(&x,&y);
    LONGS_EQUAL( 50, x);
    LONGS_EQUAL(100, y);

    robot->getAngle(&angle);
    DOUBLES_EQUAL(1.0, angle, 0.0);
}

TEST(Robot, GetDistance)
{
    robot->setPosition(50, 100);
    robot->setAngle(1.0);

    worldPtr->setExpectionOfGetDistance(50, 100, 1.0);
    worldPtr->setDummyDistance(100);

    LONGS_EQUAL(100, robot->getDistance());
    mock().checkExpectations();
}
