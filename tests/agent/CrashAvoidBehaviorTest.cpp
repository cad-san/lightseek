#include "CppUTest/TestHarness.h"

#include "CrashAvoidBehavior.h"
#include "MockDistSensor.h"
#include "MockAction.h"

static const unsigned int dummy_id = 0x01;

TEST_GROUP(CrashAvoidBehavior)
{
    MockDistSensorPtr sensor;
    MockActionPtr action;
    CrashAvoidBehavior* behavior;

    void setup()
    {
        action = MockActionPtr(new MockAction());
        sensor = MockDistSensorPtr(new MockDistSensor());
        behavior = new CrashAvoidBehavior(dummy_id, sensor, action);

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

TEST(CrashAvoidBehavior, Turn45Degree)
{
    sensor->setDummyDistance(25);
    sensor->step();

    action->setExpectionOfRotate(45, true);

    behavior->sensing();
    behavior->perform();

    mock().checkExpectations();
}

TEST(CrashAvoidBehavior, ChangeThreshold)
{
    behavior->setThreshold(100);

    sensor->setDummyDistance(50);
    sensor->step();
    behavior->sensing();
    CHECK_EQUAL(true, behavior->isActive());

    action->setExpectionOfRotate(45, true);
    behavior->perform();
    mock().checkExpectations();
}
