#include "World.h"

static const int DEFAULT_WIDTH = 500;
static const int DEFAULT_HEIGHT = 500;

World::World()
{
    this->width = DEFAULT_WIDTH;
    this->height = DEFAULT_HEIGHT;
}

World::World(int width, int height)
{
    this->width = width;
    this->height = height;
}

World::~World()
{
}

bool World::addObstacle(const ObstaclePtr& new_obstacle)
{
    int x, y, w, h;

    if(new_obstacle.get() == NULL)
        return false;

    new_obstacle->getPosition(&x, &y);

    if(!isValidPosition(x,y))
        return false;

    new_obstacle->getDimension(&w, &h);

    if(!isValidPosition(x + w - 1, y + h -1))
        return false;

    obstacles.push_back(new_obstacle);

    return true;
}

bool World::isObstacleArea(int x, int y) const
{
    for(unsigned int i = 0; i < obstacles.size(); i++)
    {
        if(obstacles.at(i)->isInArea(x, y))
            return true;
    }
    return false;
}

int World::getDistance(int x, int y, double angle) const
{
    return INVALID_DISTANCE;
}

bool World::isValidPosition(int x, int y) const
{
    return ( 0 <= x && x < width ) && ( 0 <= y && y < height );
}
