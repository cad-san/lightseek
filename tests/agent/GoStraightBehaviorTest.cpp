#include "CppUTest/TestHarness.h"

#include "GoStraightBehavior.h"
#include "MockDistSensor.h"
#include "MockAction.h"

static const unsigned int dummy_id = 0x01;

TEST_GROUP(GoStraightBehavior)
{
    MockDistSensorPtr sensor;
    MockActionPtr action;
    GoStraightBehavior* behavior;

    void setup()
    {
        action = MockActionPtr(new MockAction());
        sensor = MockDistSensorPtr(new MockDistSensor());
        behavior = new GoStraightBehavior(dummy_id, sensor, action);

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
    sensor->setDummyDistance(25);
    sensor->step();

    behavior->sensing();

    CHECK_EQUAL(true, behavior->isActive());
}

TEST(GoStraightBehavior, NotActiveAfterSensing)
{
    sensor->setDummyDistance(24);
    sensor->step();

    behavior->sensing();

    CHECK_EQUAL(false, behavior->isActive());
}

TEST(GoStraightBehavior, Perform)
{
    sensor->setDummyDistance(75);
    sensor->step();

    action->setExpectionOfMoveFront(25, true);

    behavior->sensing();
    behavior->perform();

    mock().checkExpectations();
}

TEST(GoStraightBehavior, ChangeThreshold)
{
    behavior->setThreshold(50);

    sensor->setDummyDistance(100);
    sensor->step();

    behavior->sensing();
    CHECK_EQUAL(true, behavior->isActive());

    action->setExpectionOfMoveFront(25, true);
    behavior->perform();
    mock().checkExpectations();
}
