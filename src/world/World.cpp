#include "World.h"

static const int DEFAULT_WIDTH = 500;
static const int DEFAULT_HEIGHT = 500;

static const Geo::Point INVALID_POINT(World::INVALID_COORD, World::INVALID_COORD);

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
    Geo::Point min, max;

    if(new_obstacle.get() == NULL)
        return false;

    min = new_obstacle->getMinPoint();
    max = new_obstacle->getMaxPoint();

    if(!isValidPosition(min))
        return false;

    if(!isValidPosition(max))
        return false;

    if(isObstacleArea( *new_obstacle.get() ))
        return false;

    obstacles.push_back(new_obstacle);

    return true;
}

bool World::isObstacleArea(const Obstacle& obstacle) const
{
    for(unsigned int i = 0; i < obstacles.size(); i++)
    {
        if( obstacles.at(i)->isInArea(obstacle) )
            return true;
    }
    return false;
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

Geo::Line World::getEdge(int index) const
{
    Geo::Line edges[4];

    if(index < 0 || index >= 4)
        return Geo::Line(INVALID_POINT, INVALID_POINT);

    edges[0] = Geo::Line(width-1,        0, width-1, height-1 );     // 右
    edges[1] = Geo::Line(      0, height-1, width-1, height-1 );     // 下
    edges[2] = Geo::Line(      0,        0,       0, height-1 );     // 左
    edges[3] = Geo::Line(      0,        0, width-1,        0 );     // 上

    return edges[index];
}

int World::getDistToEdge(int x, int y, int angle) const
{
    if(!isValidPosition(x, y))
        return INVALID_DISTANCE;

    Geo::Point src = Geo::Point(x, y);

    int length = getMaxLength();
    double radian = Geo::convert_radian(angle);
    Geo::Line line = Geo::Line( src, length, radian );

    for(unsigned int i = 0; i < 4; i++)
    {
        Geo::Line edge = getEdge(i);

        if(!Geo::intersects_s(edge, line))
            continue;

        Geo::Point tgt = Geo::intersection_s(edge, line);

        return static_cast<int>( Geo::distance(src, tgt) );
    }

    return INVALID_DISTANCE;
}

int World::getDistance(int x, int y, int angle) const
{
    if(!isValidPosition(x, y))
        return INVALID_DISTANCE;

    int min_dist = getDistToEdge(x, y, angle);

    for(unsigned int i = 0; i < obstacles.size(); i++)
    {
        int dist = obstacles.at(i)->getDistance(x, y, angle);

        if(dist != INVALID_DISTANCE && dist < min_dist)
            min_dist = dist;
    }

    return min_dist;
}

bool World::isValidPosition(int x, int y) const
{
    return ( 0 <= x && x < width ) && ( 0 <= y && y < height );
}

bool World::isValidPosition(const Geo::Point& p) const
{
    return isValidPosition( static_cast<int>(p.x()), static_cast<int>(p.y()) );
}


int World::getMaxLength() const
{
    return static_cast<int>( Geo::Point(width, height).length() );
}
