#include "CppUTest/TestHarness.h"

#include "SquareObstacle.h"
#include "World.h"

static const int START_X = 100;
static const int START_Y = 100;
static const int WIDTH   = 100;
static const int HEIGHT  = 100;

static const int X_MIN = START_X;
static const int Y_MIN = START_Y;
static const int X_MAX = X_MIN + WIDTH - 1;
static const int Y_MAX = Y_MIN + HEIGHT - 1;

TEST_GROUP(SquareObstacle)
{
    SquareObstacle* square;

    void setup()
    {
        square = new SquareObstacle(START_X, START_Y, WIDTH, HEIGHT);
    }

    void teardown()
    {
        delete square;
    }
};

TEST(SquareObstacle, Init)
{
    int x, y;
    int width, height;

    square->getPosition(&x, &y);
    LONGS_EQUAL(START_X, x);
    LONGS_EQUAL(START_Y, y);

    square->getDimension(&width, &height);
    LONGS_EQUAL(WIDTH, width);
    LONGS_EQUAL(HEIGHT, height);
}

TEST(SquareObstacle, CheckArea)
{
    CHECK_EQUAL(true,  square->isInArea(X_MIN, Y_MIN));
    CHECK_EQUAL(true,  square->isInArea(X_MAX, Y_MAX));
    CHECK_EQUAL(false, square->isInArea(X_MIN - 1, Y_MIN - 1));
    CHECK_EQUAL(false, square->isInArea(X_MAX + 1, Y_MAX + 1));
}

TEST(SquareObstacle, GetDistance)
{
    LONGS_EQUAL(50, square->getDistance(X_MIN - 50, Y_MIN + 50,  0));
    LONGS_EQUAL(50, square->getDistance(X_MIN + 50, Y_MIN - 50, 90));
    LONGS_EQUAL(50, square->getDistance(X_MAX + 50, Y_MIN + 50,180));
    LONGS_EQUAL(50, square->getDistance(X_MIN + 50, Y_MAX + 50,270));
}

TEST(SquareObstacle, GetDistanceAngled)
{
    LONGS_EQUAL(141, square->getDistance(X_MIN -  50, Y_MIN - 100,  45));
    LONGS_EQUAL(141, square->getDistance(X_MIN + 100, Y_MIN - 100, 135));
    LONGS_EQUAL(141, square->getDistance(X_MAX + 100, Y_MIN + 100, 225));
    LONGS_EQUAL(141, square->getDistance(X_MIN -  50, Y_MAX + 100, 315));
}

TEST(SquareObstacle, GetDistanceNoIntersection)
{
    LONGS_EQUAL(World::INVALID_DISTANCE, square->getDistance(X_MIN - 100, Y_MIN -   1,  0));
    LONGS_EQUAL(World::INVALID_DISTANCE, square->getDistance(X_MIN - 100, Y_MIN +   1, 45));
    LONGS_EQUAL(World::INVALID_DISTANCE, square->getDistance(X_MIN -   1, Y_MIN - 100, 90));
}

TEST(SquareObstacle, GetDistanceOppositeAngle)
{
    LONGS_EQUAL(World::INVALID_DISTANCE, square->getDistance(X_MIN -  50, Y_MIN + 50, 180));
    LONGS_EQUAL(World::INVALID_DISTANCE, square->getDistance(X_MIN +  50, Y_MIN - 50, -90));
    LONGS_EQUAL(World::INVALID_DISTANCE, square->getDistance(X_MAX +  50, Y_MAX - 50,   0));
    LONGS_EQUAL(World::INVALID_DISTANCE, square->getDistance(X_MAX -  50, Y_MAX + 50,  90));
}
