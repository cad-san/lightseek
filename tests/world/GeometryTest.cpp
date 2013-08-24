#include "CppUTest/TestHarness.h"

#include "Geometry.h"

TEST_GROUP(Geometry)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(Geometry, Distance)
{
    Geo::Point a(100, 100);
    Geo::Point b(400, 500);

    LONGS_EQUAL(500, Geo::distance(a, b));
}
