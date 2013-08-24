#ifndef D_GEOMETRY_H
#define D_GEOMETRY_H

#include <complex>

namespace Geo {
typedef double type;

class Point : public std::complex<type>
{
public:
    Point( const type& x, const type& y);
    ~Point();

    type x() const;
    type y() const;

};

type dot(const Point& a, const Point& b);
type cross(const Point& a, const Point& b);
type distance(const Point& a, const Point& b);
}

#endif
