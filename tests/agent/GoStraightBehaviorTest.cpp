#include "CppUTest/TestHarness.h"

#include "GoStraightBehavior.h"
#include "MockDistSensor.h"
#include "MockAction.h"

#include <boost/make_shared.hpp>

static const unsigned int dummy_id = 0x01;

TEST_GROUP(GoStraightBehavior)
{
    MockDistSensorPtr sensor;
    MockActionPtr action;
    GoStraightBehavior* behavior;

    void setup()
    {
        action = boost::make_shared<MockAction>();
        sensor = boost::make_shared<MockDistSensor>();
        behavior = new GoStraightBehavior(dummy_id, sensor, action);

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
    sensor->setExpectionOfGetFrontDist(25);

    behavior->sensing();

    CHECK_EQUAL(true, behavior->isActive());
}

TEST(GoStraightBehavior, NotActiveAfterSensing)
{
    sensor->setExpectionOfGetFrontDist(24);

    behavior->sensing();

    CHECK_EQUAL(false, behavior->isActive());
}

TEST(GoStraightBehavior, Perform)
{
    sensor->setExpectionOfGetFrontDist(75);
    action->setExpectionOfMoveFront(25, true);

    behavior->sensing();
    behavior->perform();

    mock().checkExpectations();
}

TEST(GoStraightBehavior, ChangeThreshold)
{
    behavior->setThreshold(50);

    sensor->setExpectionOfGetFrontDist(100);
    action->setExpectionOfMoveFront(25, true);

    behavior->sensing();
    behavior->perform();

    CHECK_EQUAL(true, behavior->isActive());
    mock().checkExpectations();
}
