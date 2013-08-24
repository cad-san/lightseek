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

class Line
{
private:
    Point p_s;
    Point p_e;
public:
    Line( const type& x_s, const type& y_s,
          const type& x_e, const type& y_e );
    Line( const Point& p_s, const Point& p_e );

    type length(void) const;
};

type dot(const Point& a, const Point& b);
type cross(const Point& a, const Point& b);
type distance(const Point& a, const Point& b);
}

#endif
