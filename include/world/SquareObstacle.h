#ifndef D_SQUARE_OBSTACLE_H
#define D_SQUARE_OBSTACLE_H

#include "Obstacle.h"
#include "Geometry.h"
#include <vector>

class SquareObstacle : public Obstacle
{
public:
    SquareObstacle(int x, int y, int width, int height);
    ~SquareObstacle();

    virtual std::vector<Geo::Point> getVertexList() const;
    virtual std::vector<Geo::Line> getEdgeList() const;

    virtual bool isInArea(int x, int y) const;
    virtual bool isInArea(const Geo::Point& p) const;
    virtual bool isInArea(const Obstacle& obstacle) const;
    virtual int getDistance(int x, int y, int angle) const;

};

#endif
