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

TEST(Geometry, LineLength)
{
    Geo::Line line1(100, 100, 400, 500);
    Geo::Line line2(Geo::Point(100, 100), Geo::Point(400, 500));

    LONGS_EQUAL(500, line1.length());
    LONGS_EQUAL(500, line2.length());
}
