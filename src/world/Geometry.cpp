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
