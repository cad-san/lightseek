#include "CppUTest/TestHarness.h"

#include "SquareObstacle.h"

TEST_GROUP(SquareObstacle)
{
    SquareObstacle* square;

    void setup()
    {
        square = new SquareObstacle(100, 100, 100, 100);
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
    LONGS_EQUAL(100, x);
    LONGS_EQUAL(100, y);

    square->getDimension(&width, &height);
    LONGS_EQUAL(100, width);
    LONGS_EQUAL(100, height);
}

TEST(SquareObstacle, CheckArea)
{
    CHECK_EQUAL(false, square->isInArea( 99,  99));
    CHECK_EQUAL(true,  square->isInArea(100, 100));
    CHECK_EQUAL(true,  square->isInArea(199, 199));
    CHECK_EQUAL(false, square->isInArea(200, 200));
}
