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

TEST(Geometry, SegmentIntersection)
{
    Geo::Line line1(  0, 100, 200, 100);
    Geo::Line line2(100,   0, 100, 200);

    CHECK_EQUAL(true, Geo::intersects_l(line1, line2));
    CHECK_EQUAL(true, Geo::intersects_s(line1, line2));

    Geo::Point intersect = Geo::intersection_s(line1, line2);

    LONGS_EQUAL(100, intersect.x());
    LONGS_EQUAL(100, intersect.y());
}

TEST(Geometry, LineIntersection)
{
    Geo::Line line1(  0, 100,  50, 100);
    Geo::Line line2(100,   0, 100,  50);

    CHECK_EQUAL(true,  Geo::intersects_l(line1, line2));
    CHECK_EQUAL(false, Geo::intersects_s(line1, line2));

    Geo::Point intersect = Geo::intersection_l(line1, line2);

    LONGS_EQUAL(100, intersect.x());
    LONGS_EQUAL(100, intersect.y());
}
