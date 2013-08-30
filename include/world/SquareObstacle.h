#ifndef D_SQUARE_OBSTACLE_H
#define D_SQUARE_OBSTACLE_H

#include "Obstacle.h"

class SquareObstacle : public Obstacle
{

public:
    SquareObstacle(int x, int y, int width, int height);
    ~SquareObstacle();

    virtual bool isInArea(int x, int y) const;
    virtual int getDistance(int x, int y, double angle) const;

};

#endif