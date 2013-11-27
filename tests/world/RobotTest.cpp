#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "Robot.h"
#include "MockWorld.h"

#include <boost/make_shared.hpp>

TEST_GROUP(Robot)
{
    MockWorldPtr worldPtr;
    Robot* robot;

    void setup()
    {
        worldPtr = boost::make_shared<MockWorld>();
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
    int angle;

    robot->getPosition(&x,&y);
    LONGS_EQUAL(World::INVALID_COORD, x);
    LONGS_EQUAL(World::INVALID_COORD, y);

    robot->getAngle(&angle);
    LONGS_EQUAL(0, angle);
}

TEST(Robot, SetPosition)
{
    int x, y;
    int angle;

    robot->setPosition(50, 100);
    robot->setAngle(90);

    robot->getPosition(&x,&y);
    LONGS_EQUAL( 50, x);
    LONGS_EQUAL(100, y);

    robot->getAngle(&angle);
    LONGS_EQUAL(90, angle);
}

TEST(Robot, GetDistance)
{
    robot->setPosition(50, 100);
    robot->setAngle(90);

    worldPtr->setExpectionOfGetDistance(50, 100, 90);
    worldPtr->setDummyDistance(100);

    LONGS_EQUAL(100, robot->getDistance());
    mock().checkExpectations();
}

TEST(Robot, MoveFront)
{
    int x, y;
    int angle;

    robot->setPosition(50, 100);
    robot->setAngle(0);

    robot->moveFront(50);

    robot->getPosition(&x,&y);
    LONGS_EQUAL(100, x);
    LONGS_EQUAL(100, y);

    robot->getAngle(&angle);
    LONGS_EQUAL(0, angle);
}

TEST(Robot, Rotate)
{
    int x, y;
    int angle;

    robot->setPosition(50, 100);
    robot->setAngle(0);

    robot->rotate(90);

    robot->getPosition(&x,&y);
    LONGS_EQUAL( 50, x);
    LONGS_EQUAL(100, y);

    robot->getAngle(&angle);
    LONGS_EQUAL(90, angle);
}

TEST(Robot, ChangeSize)
{
    Robot robot(worldPtr, 10);
    int radius;
    robot.getSize(&radius);
    LONGS_EQUAL(10, radius);
}
