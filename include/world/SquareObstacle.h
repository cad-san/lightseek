#ifndef D_SQUARE_OBSTACLE_H
#define D_SQUARE_OBSTACLE_H

#include "Obstacle.h"
#include "Geometry.h"

class SquareObstacle : public Obstacle
{
private:
    Geo::Line getEdge(int index) const;

public:
    SquareObstacle(int x, int y, int width, int height);
    ~SquareObstacle();

    virtual bool isInArea(int x, int y) const;
    virtual bool isInArea(const Obstacle& obstacle) const;
    virtual int getDistance(int x, int y, int angle) const;

};

#endif
