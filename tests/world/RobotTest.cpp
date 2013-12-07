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

    void ROBOT_POSITIONS_EQUAL(const Robot* robot, const int x, const int y, const int angle)
    {
        int actual_x, actual_y, actual_angle;
        robot->getPosition(&actual_x, &actual_y);
        robot->getAngle(&actual_angle);

        LONGS_EQUAL(x, actual_x);
        LONGS_EQUAL(y, actual_y);
        LONGS_EQUAL(angle, actual_angle);
    }
};

TEST(Robot, Init)
{
    ROBOT_POSITIONS_EQUAL(robot,
                          World::INVALID_COORD,
                          World::INVALID_COORD, 0);
}

TEST(Robot, SetPosition)
{
    robot->setPosition(50, 100);
    robot->setAngle(90);

    ROBOT_POSITIONS_EQUAL(robot, 50, 100, 90);
}

TEST(Robot, GetFrontDistance)
{
    robot->setPosition(50, 100);
    robot->setAngle(90);

    worldPtr->setExpectionOfGetDistance(50, 100, 90);
    worldPtr->setDummyDistance(100);

    LONGS_EQUAL(100, robot->getFrontDistance());
    mock().checkExpectations();
}

TEST(Robot, GetLeftSideDistance)
{
    robot->setPosition(50, 100);
    robot->setAngle(90);

    worldPtr->setExpectionOfGetDistance(50, 100, 0);
    worldPtr->setDummyDistance(100);

    LONGS_EQUAL(100, robot->getLeftSideDistance());
    mock().checkExpectations();
}

TEST(Robot, GetRightSideDistance)
{
    robot->setPosition(50, 100);
    robot->setAngle(0);

    worldPtr->setExpectionOfGetDistance(50, 100, 90);
    worldPtr->setDummyDistance(100);

    LONGS_EQUAL(100, robot->getRightSideDistance());
    mock().checkExpectations();
}

TEST(Robot, MoveFront)
{
    robot->setPosition(50, 100);
    robot->setAngle(0);

    robot->moveFront(50);

    ROBOT_POSITIONS_EQUAL(robot, 100, 100, 0);
}

TEST(Robot, Rotate)
{
    robot->setPosition(50, 100);
    robot->setAngle(0);

    robot->rotate(90);

    ROBOT_POSITIONS_EQUAL(robot, 50, 100, 90);
}

TEST(Robot, ChangeSize)
{
    Robot robot(worldPtr, 10);
    int radius;
    robot.getSize(&radius);
    LONGS_EQUAL(10, radius);
}
