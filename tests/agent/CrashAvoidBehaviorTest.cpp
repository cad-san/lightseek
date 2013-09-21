#include "CppUTest/TestHarness.h"

#include "CrashAvoidBehavior.h"
#include "MockDistSensor.h"
#include "MockAction.h"

TEST_GROUP(CrashAvoidBehavior)
{
    MockDistSensorPtr sensor;
    MockActionPtr action;
    Behavior* behavior;

    void setup()
    {
        action = MockActionPtr(new MockAction());
        sensor = MockDistSensorPtr(new MockDistSensor());
        behavior = new CrashAvoidBehavior(sensor, action);

        sensor->init();
        behavior->init();
    }

    void teardown()
    {
        mock().clear();
        delete behavior;
    }
};

TEST(CrashAvoidBehavior, Init)
{
    CHECK_EQUAL(false, behavior->isActive());
}

TEST(CrashAvoidBehavior, ActiveAfterSensing)
{
    sensor->setDummyDistance(0);
    sensor->step();

    behavior->sensing();

    CHECK_EQUAL(true, behavior->isActive());
}

TEST(CrashAvoidBehavior, NotActiveAfterSensing)
{
    sensor->setDummyDistance(50);
    sensor->step();

    behavior->sensing();

    CHECK_EQUAL(false, behavior->isActive());
}

TEST(CrashAvoidBehavior, Perform)
{
    sensor->setDummyDistance(0);
    sensor->step();

    action->setExpectionOfRotate(90, true);

    behavior->sensing();
    behavior->perform();

    mock().checkExpectations();
}
