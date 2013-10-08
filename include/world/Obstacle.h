#ifndef D_OBSTACLE_H
#define D_OBSTACLE_H

#include <Geometry.h>
#include <boost/shared_ptr.hpp>

class Obstacle
{
protected:
    int x_;
    int y_;
    int width_;
    int height_;
public:
    Obstacle(int x, int y, int width, int height)
    {
        this->x_ = x;
        this->y_ = y;
        this->width_ = width;
        this->height_ = height;
    }

    virtual ~Obstacle() {}

    void getPosition(int* x, int* y) const
    {
        if(x == NULL || y == NULL)
            return;

        *x = this->x_;
        *y = this->y_;
    }

    void getDimension(int* w, int* h) const
    {
        if(w == NULL || h == NULL)
            return;

        *w = this->width_;
        *h = this->height_;
    }

    Geo::Point getMinPoint() const
    {
        return Geo::Point(x_, y_);
    }

    Geo::Point getMaxPoint() const
    {
        return Geo::Point(x_ + width_ - 1, y_ + height_ - 1);
    }

    virtual bool isInArea(int x, int y) const = 0;
    virtual bool isInArea(const Geo::Point& p) const = 0;
    virtual bool isInArea(const Obstacle& obstacle) const = 0;
    virtual int getDistance(int x, int y, int angle) const = 0;
};

typedef boost::shared_ptr<Obstacle> ObstaclePtr;

#endif
