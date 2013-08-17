#include "CppUTest/TestHarness.h"

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
