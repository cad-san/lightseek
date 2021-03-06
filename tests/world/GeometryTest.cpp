#include "CppUTest/TestHarness.h"

#include "Geometry.h"

static const double EPS = 1e-5;

TEST_GROUP(Geometry)
{
    void setup()
    {
    }

    void teardown()
    {
    }

    void POINT_EQUAL(Geo::Point expect, Geo::Point actual)
    {
        LONGS_EQUAL(expect.x<int>(), actual.x<int>());
        LONGS_EQUAL(expect.y<int>(), actual.y<int>());
    }
};

TEST(Geometry, DefaultPoint)
{
    Geo::Point p_init;
    Geo::Point p_zero(0, 0);

    POINT_EQUAL(p_zero, p_init);
}

TEST(Geometry, DefaultLine)
{
    Geo::Line l_init;
    Geo::Point p_zero(0, 0);

    POINT_EQUAL(p_zero, l_init.s());
    POINT_EQUAL(p_zero, l_init.e());
}

TEST(Geometry, DegreeRadianConversion)
{
    DOUBLES_EQUAL( Geo::PI / 4, Geo::convert_radian(45), EPS);
    DOUBLES_EQUAL( 45, Geo::convert_degree(Geo::PI / 4), EPS);
}

TEST(Geometry, Distance)
{
    Geo::Point a(100, 100);
    Geo::Point b(400, 500);

    LONGS_EQUAL(500, Geo::distance(a, b));
}

TEST(Geometry, Angle)
{
    Geo::Point a(100, 100);
    Geo::Point b(200, 100);
    Geo::Point c(100, 200);

    DOUBLES_EQUAL( 0,           Geo::angle(a, b), EPS );
    DOUBLES_EQUAL( Geo::PI / 2, Geo::angle(a, c), EPS );
}

TEST(Geometry, LengthFromOrigin)
{
    Geo::Point point(300, 400);

    LONGS_EQUAL(500, Geo::length(point));
    LONGS_EQUAL(500, point.length());
    LONGS_EQUAL(500, point.length<int>());
}

TEST(Geometry, LineLength)
{
    Geo::Line line1(100, 100, 400, 500);
    Geo::Line line2(Geo::Point(100, 100), Geo::Point(400, 500));

    LONGS_EQUAL(500, line1.length());
    LONGS_EQUAL(500, line2.length());
}

TEST(Geometry, CastedLineLength)
{
    Geo::Line line(100, 100, 400, 500);

    LONGS_EQUAL(500, line.length<int>());
}

TEST(Geometry, LineAngle)
{
    Geo::Line line1(200, 200, 300, 300);
    Geo::Line line2(200, 200, 300, 100);
    Geo::Line line3(200, 200, 100, 300);
    Geo::Line line4(200, 200, 100, 100);

    DOUBLES_EQUAL(  Geo::PI * 1 / 4, line1.angle(), EPS );
    DOUBLES_EQUAL( -Geo::PI * 1 / 4, line2.angle(), EPS );
    DOUBLES_EQUAL(  Geo::PI * 3 / 4, line3.angle(), EPS );
    DOUBLES_EQUAL( -Geo::PI * 3 / 4, line4.angle(), EPS );
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
