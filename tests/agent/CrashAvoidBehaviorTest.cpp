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
    }

    void teardown()
    {
        delete behavior;
    }
};

TEST(CrashAvoidBehavior, Init)
{
    behavior->init();
    CHECK_EQUAL(false, behavior->isActive());
}
