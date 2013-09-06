#ifndef D_OBSTACLE_H
#define D_OBSTACLE_H

#include <Geometry.h>
#include <boost/shared_ptr.hpp>

class Obstacle
{
protected:
    int x;
    int y;
    int width;
    int height;
public:
    Obstacle(int x, int y, int width, int height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    virtual ~Obstacle() {};

    void getPosition(int* x, int* y) const
    {
        if(x == NULL || y == NULL)
            return;

        *x = this->x;
        *y = this->y;
    }

    void getDimension(int* w, int* h) const
    {
        if(w == NULL || h == NULL)
            return;

        *w = this->width;
        *h = this->height;
    }

    Geo::Point getMinPoint() const
    {
        return Geo::Point(x, y);
    }

    Geo::Point getMaxPoint() const
    {
        return Geo::Point(x+width-1, y+height-1);
    }

    virtual bool isInArea(int x, int y) const = 0;
    virtual bool isInArea(const Obstacle& obstacle) const = 0;
    virtual int getDistance(int x, int y, int angle) const = 0;
};

typedef boost::shared_ptr<Obstacle> ObstaclePtr;

#endif
