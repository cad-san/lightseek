#ifndef D_GEOMETRY_H
#define D_GEOMETRY_H

#include <complex>

namespace Geo {
typedef double type;

static const double PI = 3.141592;

class Point : public std::complex<type>
{
public:
    Point();
    Point( const type& x, const type& y );
    Point( const std::complex<type>& super );
    ~Point();

    type x() const;
    type y() const;

    type length(void) const;
};

class Line
{
private:
    Point p_s;
    Point p_e;
public:
    Line();
    Line( const type& x_s, const type& y_s,
          const type& x_e, const type& y_e );
    Line( const Point& p_s, const Point& p_e );
    Line( const Point& p_s, const type& length, const type& radian );

    Point s() const;
    Point e() const;

    type length(void) const;
};

type convert_radian(const type& degree);
type convert_degree(const type& radian);

type length(const Point& a);
type dot(const Point& a, const Point& b);
type cross(const Point& a, const Point& b);
type distance(const Point& a, const Point& b);
bool equals(const type& a, const type& b);

bool intersects_s(const Line& a, const Line& b);
Point intersection_s(const Line& a, const Line& b);
bool intersects_l(const Line& a, const Line& b);
Point intersection_l(const Line& a, const Line& b);
}

#endif
