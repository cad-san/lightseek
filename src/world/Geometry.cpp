#include "Geometry.h"

#include <math.h>

namespace Geo
{
Point::Point( const type& x, const type& y)
    : std::complex<type>(x, y)
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

Line::Line( const type& x_s, const type& y_s,
            const type& x_e, const type& y_e )
    : p_s(x_s, y_s), p_e(x_e, y_e)
{
}

Line::Line( const Point& p_s, const Point& p_e )
    : p_s(p_s), p_e(p_e)
{
}

type Line::length() const
{
    return Geo::distance(this->p_s, this->p_e);
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
}
