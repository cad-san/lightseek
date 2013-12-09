#include "CppUTest/TestHarness.h"

#include "CrashAvoidBehavior.h"
#include "MockDistSensor.h"
#include "MockAction.h"

#include <boost/make_shared.hpp>

static const unsigned int dummy_id = 0x01;

TEST_GROUP(CrashAvoidBehavior)
{
    MockDistSensorPtr sensor;
    MockActionPtr action;
    CrashAvoidBehavior* behavior;

    void setup()
    {
        action = boost::make_shared<MockAction>();
        sensor = boost::make_shared<MockDistSensor>();
        behavior = new CrashAvoidBehavior(dummy_id, sensor, action);

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
    sensor->setExpectDistance(0, 100, 100);

    behavior->sensing();

    CHECK_EQUAL(true, behavior->isActive());
    mock().checkExpectations();
}

TEST(CrashAvoidBehavior, NotActiveAfterSensing)
{
    sensor->setExpectionOfGetFrontDist(50);

    behavior->sensing();

    CHECK_EQUAL(false, behavior->isActive());
    mock().checkExpectations();
}

TEST(CrashAvoidBehavior, Perform)
{
    sensor->setExpectDistance(0, 100, 100);
    action->setExpectionOfRotate(90, true);

    behavior->sensing();
    behavior->perform();

    mock().checkExpectations();
}

TEST(CrashAvoidBehavior, Turn45Degree)
{
    sensor->setExpectDistance(25, 100, 100);
    action->setExpectionOfRotate(45, true);

    behavior->sensing();
    behavior->perform();

    mock().checkExpectations();
}

TEST(CrashAvoidBehavior, ChangeThreshold)
{
    behavior->setThreshold(100);

    sensor->setExpectDistance(50, 100, 100);
    action->setExpectionOfRotate(45, true);

    behavior->sensing();
    behavior->perform();

    CHECK_EQUAL(true, behavior->isActive());
    mock().checkExpectations();
}

TEST(CrashAvoidBehavior, TurnRight)
{
    sensor->setExpectDistance(0, 100, 99);
    action->setExpectionOfRotate(-90, true);

    behavior->sensing();
    behavior->perform();

    mock().checkExpectations();
}

TEST(CrashAvoidBehavior, TurnLeft)
{
    sensor->setExpectDistance(0, 99, 100);
    action->setExpectionOfRotate(+90, true);

    behavior->sensing();
    behavior->perform();

    mock().checkExpectations();
}
