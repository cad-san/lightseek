#ifndef D_WORLD_H
#define D_WORLD_H

#include <vector>
#include <boost/shared_ptr.hpp>

#include "Geometry.h"
#include "Obstacle.h"

class World
{
private:
    int width;
    int height;

    std::vector< ObstaclePtr > obstacles;

    std::vector<Geo::Line> getEdgeList() const;

public:
    static const int INVALID_COORD = -1;
    static const int INVALID_DISTANCE = -1;

    World();
    World(int width, int height);
    virtual ~World();

    virtual int getDistance(int x, int y, int angle) const;
    virtual int getDistToEdge(int x, int y, int angle) const;

    int getMaxLength() const;
    bool isValidPosition(int x, int y) const;
    bool isValidPosition(const Geo::Point& p) const;

    bool addObstacle(const ObstaclePtr& obstacle);
    bool isObstacleArea(int x, int y) const;
    bool isObstacleArea(const Obstacle& obstacle) const;
};

typedef boost::shared_ptr<World> WorldPtr;

#endif
