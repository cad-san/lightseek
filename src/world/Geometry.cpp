#include "Geometry.h"

#include <math.h>

static const double EPS = 1e-10;

namespace Geo
{

Point::Point() : std::complex<type>(0, 0)
{
}

Point::Point( const type& x_coord, const type& y_coord)
    : std::complex<type>(x_coord, y_coord)
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

Line::Line() : p_s_(0, 0), p_e_(0, 0)
{
}

Line::Line( const type& x_s, const type& y_s,
            const type& x_e, const type& y_e )
    : p_s_(x_s, y_s), p_e_(x_e, y_e)
{
}

Line::Line( const Point& p_s, const Point& p_e )
    : p_s_(p_s), p_e_(p_e)
{
}

Line::Line( const Point& p_s, const type& rho, const type& theta)
    : p_s_(p_s), p_e_(p_s + std::polar(rho, theta))
{
}

Point Line::s() const
{
    return p_s_;
}

Point Line::e() const
{
    return p_e_;
}

type Line::length() const
{
    return Geo::distance(this->p_s_, this->p_e_);
}

type Line::angle() const
{
    return Geo::angle(this->p_s_, this->p_e_);
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
    return std::abs(point);
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
    return std::abs(a - b);
}

type angle(const Point& a, const Point& b)
{
    return std::arg(b - a);
}

bool equals(const type& a, const type& b)
{
    return (std::abs(a-b) < EPS);
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

    type dist_s = std::abs( cross( b_vector, a.s() - b.s() ) );
    type dist_e = std::abs( cross( b_vector, a.e() - b.s() ) );

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
