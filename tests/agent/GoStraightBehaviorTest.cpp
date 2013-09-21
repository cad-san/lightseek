#include "CppUTest/TestHarness.h"

#include "GoStraightBehavior.h"
#include "MockDistSensor.h"
#include "MockAction.h"

TEST_GROUP(GoStraightBehavior)
{
    MockDistSensorPtr sensor;
    MockActionPtr action;
    Behavior* behavior;

    void setup()
    {
        action = MockActionPtr(new MockAction());
        sensor = MockDistSensorPtr(new MockDistSensor());
        behavior = new GoStraightBehavior(sensor, action);

        sensor->init();
        behavior->init();
    }

    void teardown()
    {
        mock().clear();
        delete behavior;
    }
};

TEST(GoStraightBehavior, Init)
{
    CHECK_EQUAL(false, behavior->isActive());
}

TEST(GoStraightBehavior, ActiveAfterSensing)
{
    sensor->setDummyDistance(50);
    sensor->step();

    behavior->sensing();

    CHECK_EQUAL(true, behavior->isActive());
}

TEST(GoStraightBehavior, NotActiveAfterSensing)
{
    sensor->setDummyDistance(49);
    sensor->step();

    behavior->sensing();

    CHECK_EQUAL(false, behavior->isActive());
}

TEST(GoStraightBehavior, Perform)
{
    sensor->setDummyDistance(100);
    sensor->step();

    action->setExpectionOfMoveFront(25, true);

    behavior->sensing();
    behavior->perform();

    mock().checkExpectations();
}
