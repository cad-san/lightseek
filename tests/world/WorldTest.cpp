#include "CppUTest/TestHarness.h"

#include "World.h"

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
