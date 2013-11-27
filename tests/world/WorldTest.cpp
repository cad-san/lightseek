#include "CppUTest/TestHarness.h"

#include "World.h"
#include "MockObstacle.h"

#include <boost/make_shared.hpp>

static const int WORLD_WIDTH = 200;
static const int WORLD_HEIGHT = 200;

static const int X_MIN = 0;
static const int Y_MIN = 0;
static const int X_MAX = WORLD_WIDTH - 1;
static const int Y_MAX = WORLD_HEIGHT - 1;

TEST_GROUP(World)
{
    World* world;

    void setup()
    {
        world = new World(WORLD_WIDTH, WORLD_HEIGHT);
    }

    void teardown()
    {
        mock().clear();
        delete world;
    }
};

TEST(World, Init)
{
    CHECK(world->isValidPosition(X_MIN, Y_MIN));
    CHECK(world->isValidPosition(X_MAX, Y_MAX));
}

TEST(World, AddObstacle)
{
    MockObstaclePtr obstacle = boost::make_shared<MockObstacle>(0, 0, 50, 50);

    CHECK(world->addObstacle(obstacle));
    CHECK(world->isObstacleArea(25,25));
}

TEST(World, AddInvalidObstacle)
{
    MockObstaclePtr no_osbtacle;
    MockObstaclePtr invalid_min = boost::make_shared<MockObstacle>(X_MIN - 1, Y_MIN - 1, WORLD_WIDTH, WORLD_HEIGHT);
    MockObstaclePtr invalid_max = boost::make_shared<MockObstacle>(X_MIN, Y_MIN, WORLD_WIDTH + 1, WORLD_HEIGHT + 1);

    CHECK_EQUAL(false, world->addObstacle(no_osbtacle));
    CHECK_EQUAL(false, world->addObstacle(invalid_min));
    CHECK_EQUAL(false, world->addObstacle(invalid_max));
}

TEST(World, AddObstacleOverlap)
{
    MockObstaclePtr obst_1 = boost::make_shared<MockObstacle>(100, 100, 50, 50);
    MockObstaclePtr obst_2 = boost::make_shared<MockObstacle>(149, 100, 50, 50);
    MockObstaclePtr obst_3 = boost::make_shared<MockObstacle>(150, 100, 50, 50);

    CHECK_EQUAL( true, world->addObstacle(obst_1));
    CHECK_EQUAL(false, world->addObstacle(obst_2));
    CHECK_EQUAL( true, world->addObstacle(obst_3));
}

TEST(World, GetDistanceNoObsacle)
{
    LONGS_EQUAL(X_MAX - 100, world->getDistance(100, 100,   0));
    LONGS_EQUAL(Y_MAX - 100, world->getDistance(100, 100,  90));
    LONGS_EQUAL(X_MIN + 100, world->getDistance(100, 100, 180));
    LONGS_EQUAL(Y_MIN + 100, world->getDistance(100, 100, 270));
}

TEST(World, GetDistanceNoObsacleAngled)
{
    LONGS_EQUAL(141, world->getDistance(X_MIN + 50, Y_MAX - 100,  45));
    LONGS_EQUAL(141, world->getDistance(X_MAX - 50, Y_MAX - 100, 135));
    LONGS_EQUAL(141, world->getDistance(X_MAX - 50, Y_MIN + 100, 225));
    LONGS_EQUAL(141, world->getDistance(X_MIN + 50, Y_MIN + 100, 315));
}

TEST(World, GetDistance)
{
    MockObstaclePtr obstacle = boost::make_shared<MockObstacle>(100, 0, 100, 100);

    obstacle->setExpectionOfGetDistance(50, 50, 0);
    obstacle->setDummyDistance(50);

    CHECK(world->addObstacle(obstacle));
    LONGS_EQUAL(50, world->getDistance(50, 50, 0));
}

TEST(World, GetDistanceNoIntersection)
{
    MockObstaclePtr obstacle = boost::make_shared<MockObstacle>(0, 0, 50, 50);

    obstacle->setExpectionOfGetDistance(100, 100, 0);
    obstacle->setDummyDistance(World::INVALID_DISTANCE);

    CHECK(world->addObstacle(obstacle));
    LONGS_EQUAL(99, world->getDistance(100, 100, 0));
}
