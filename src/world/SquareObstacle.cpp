#include "SquareObstacle.h"
#include "World.h"

SquareObstacle::SquareObstacle(int x, int y, int width, int height)
    : Obstacle(x, y, width, height)
{
}

SquareObstacle::~SquareObstacle()
{
}

bool SquareObstacle::isInArea(int x, int y) const
{
    return ( this->x <= x && x < this->x + this->width  ) &&
           ( this->y <= y && y < this->y + this->height );
}

int SquareObstacle::getDistance(int x, int y, double angle) const
{
    return World::INVALID_DISTANCE;
}
