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
