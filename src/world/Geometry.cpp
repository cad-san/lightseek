#include "Geometry.h"

#include <math.h>

static const double EPS = 1e-10;

namespace Geo
{

Point::Point() : std::complex<type>(0, 0)
{
}

Point::Point( const type& x, const type& y)
    : std::complex<type>(x, y)
{
}

Point::Point( const std::complex<type>& super)
    : std::complex<type>(super)
{
}

Point::~Point()
{
}

type Point::x() const
{
    return this->real();
}

type Point::y() const
{
    return this->imag();
}

type Point::length(void) const
{
    return Geo::length(*this);
}

Line::Line() : p_s(0, 0), p_e(0, 0)
{
}

Line::Line( const type& x_s, const type& y_s,
            const type& x_e, const type& y_e )
    : p_s(x_s, y_s), p_e(x_e, y_e)
{
}

Line::Line( const Point& p_s, const Point& p_e )
    : p_s(p_s), p_e(p_e)
{
}

Line::Line( const Point& p_s, const type& length, const type& radian)
    : p_s(p_s), p_e(p_s + std::polar(length, radian))
{
}

Point Line::s() const
{
    return p_s;
}

Point Line::e() const
{
    return p_e;
}

type Line::length() const
{
    return Geo::distance(this->p_s, this->p_e);
}

Point polar(const type& rho, const type& theta)
{
    return std::polar(rho, theta);
}

type convert_radian(const type& degree)
{
    return degree * PI / 180.0;
}

type convert_degree(const type& radian)
{
    return radian * 180 / PI;
}

type length(const Point& point)
{
    return abs(point);
}

type dot(const Point& a, const Point& b)
{
    return (a.x() * b.x() + a.y() * b.y());
}

type cross(const Point& a, const Point& b)
{
    return (a.x() * b.y() - a.y() * b.x());
}

type distance(const Point& a, const Point& b)
{
    return abs(a - b);
}

bool equals(const type& a, const type& b)
{
    return (abs(a-b) < EPS);
}

bool intersects_s(const Line& a, const Line& b)
{
    Point a_vector = a.e() - a.s();
    Point b_vector = b.e() - b.s();

    return (cross(a_vector, b.s()-a.s()) * cross(a_vector, b.e()-a.s()) < EPS) &&
           (cross(b_vector, a.s()-b.s()) * cross(b_vector, a.e()-b.s()) < EPS);
}

Point intersection_s(const Line& a, const Line& b)
{
    Point a_vector = a.e() - a.s();
    Point b_vector = b.e() - b.s();

    type dist_s = abs( cross( b_vector, a.s() - b.s() ) );
    type dist_e = abs( cross( b_vector, a.e() - b.s() ) );

    return a.s() + a_vector * dist_s / ( dist_s + dist_e );
}

bool intersects_l(const Line& a, const Line& b)
{
    Point a_vector = a.e() - a.s();
    Point b_vector = b.e() - b.s();

    return !equals(cross(a_vector, b_vector), 0.0);
}

Point intersection_l(const Line& a, const Line& b)
{
    Point a_vector = a.e() - a.s();
    Point b_vector = b.e() - b.s();

    type dist_s = cross( b_vector, b.s() - a.s() );

    return a.s() + a_vector * dist_s / ( cross(b_vector, a_vector) );
}

}
