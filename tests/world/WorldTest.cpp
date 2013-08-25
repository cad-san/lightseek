#include "CppUTest/TestHarness.h"

#include "World.h"
#include "MockObstacle.h"

#define WORLD_WIDTH 200
#define WORLD_HEIGHT 200

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
    CHECK(world->isValidPosition(0, 0));
    CHECK(world->isValidPosition(WORLD_WIDTH - 1, WORLD_HEIGHT - 1));
}

TEST(World, AddObstacle)
{
    MockObstaclePtr obstacle = MockObstaclePtr(new MockObstacle(0, 0, 50, 50));

    CHECK(world->addObstacle(obstacle));
    CHECK(world->isObstacleArea(25,25));
}

TEST(World, GetDistanceNoObsacle)
{
    int distance = world->getDistance(100, 100, 0);
    LONGS_EQUAL(99, distance);
}

TEST(World, GetDistance)
{
    MockObstaclePtr obstacle = MockObstaclePtr(new MockObstacle(100, 0, 50, 50));

    obstacle->setExpectionOfGetDistance(0, 0, 0);
    obstacle->setDummyDistance(100);

    CHECK(world->addObstacle(obstacle));
    LONGS_EQUAL(100, world->getDistance(0, 0, 0));
}

TEST(World, GetDistanceNoIntersection)
{
    MockObstaclePtr obstacle = MockObstaclePtr(new MockObstacle(0, 0, 50, 50));

    obstacle->setExpectionOfGetDistance(100, 100, 0);
    obstacle->setDummyDistance(World::INVALID_DISTANCE);

    CHECK(world->addObstacle(obstacle));
    LONGS_EQUAL(99, world->getDistance(100, 100, 0));
}
