#include "CppUTest/TestHarness.h"

#include "Robot.h"
#include "MockWorld.h"
#include "VirtualAction.h"

#include <boost/make_shared.hpp>

TEST_GROUP(VirtualAction)
{
    MockWorldPtr worldPtr;
    RobotPtr robotPtr;
    VirtualAction* action;

    void setup()
    {
        worldPtr = boost::make_shared<MockWorld>();
        robotPtr = boost::make_shared<Robot>(worldPtr);
        action = new VirtualAction(robotPtr);
    }

    void teardown()
    {
        delete action;
    }
};

TEST(VirtualAction, MoveFront)
{
    int x, y;

    robotPtr->setPosition(100, 100);
    robotPtr->setAngle(0);

    action->moveFront(10);
    robotPtr->getPosition(&x, &y);

    LONGS_EQUAL(100 + 10, x);
    LONGS_EQUAL(100, y);
}

TEST(VirtualAction, Rotate)
{
    int angle;

    robotPtr->setAngle(0);

    action->rotate(45);
    robotPtr->getAngle(&angle);

    LONGS_EQUAL(45, angle);
}
