#include "World.h"

static const int DEFAULT_WIDTH = 500;
static const int DEFAULT_HEIGHT = 500;

static const Geo::Point INVALID_POINT(World::INVALID_COORD, World::INVALID_COORD);

World::World()
{
    this->width_ = DEFAULT_WIDTH;
    this->height_ = DEFAULT_HEIGHT;
}

World::World(int width, int height)
{
    this->width_ = width;
    this->height_ = height;
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

    obstacles_.push_back(new_obstacle);

    return true;
}

const std::vector< ObstaclePtr >& World::getObstacleList() const
{
    return obstacles_;
}

bool World::isObstacleArea(const Obstacle& obstacle) const
{
    for(unsigned int i = 0; i < obstacles_.size(); i++)
    {
        if( obstacles_.at(i)->isInArea(obstacle) )
            return true;
    }
    return false;
}

bool World::isObstacleArea(int x, int y) const
{
    for(unsigned int i = 0; i < obstacles_.size(); i++)
    {
        if(obstacles_.at(i)->isInArea(x, y))
            return true;
    }
    return false;
}

std::vector<Geo::Line> World::getEdgeList() const
{
    std::vector<Geo::Line> edge_list;

    edge_list.push_back(Geo::Line(       0,         0,        0, height_-1 ));  // 左
    edge_list.push_back(Geo::Line(       0, height_-1, width_-1, height_-1 ));  // 下
    edge_list.push_back(Geo::Line(width_-1, height_-1, width_-1,         0 ));  // 右
    edge_list.push_back(Geo::Line(width_-1,         0,        0,         0 ));  // 上

    return edge_list;
}

int World::getDistToEdge(int x, int y, int angle) const
{
    if(!isValidPosition(x, y))
        return INVALID_DISTANCE;

    Geo::Point src = Geo::Point(x, y);

    int length = getMaxLength();
    double radian = Geo::convert_radian(angle);
    Geo::Line line = Geo::Line( src, length, radian );

    std::vector<Geo::Line> edge_list = getEdgeList();

    for(unsigned int i = 0; i < edge_list.size(); i++)
    {
        Geo::Line edge = edge_list.at(i);

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

    for(unsigned int i = 0; i < obstacles_.size(); i++)
    {
        int dist = obstacles_.at(i)->getDistance(x, y, angle);

        if(dist != INVALID_DISTANCE && dist < min_dist)
            min_dist = dist;
    }

    return min_dist;
}

bool World::isValidPosition(int x, int y) const
{
    return ( 0 <= x && x < width_ ) && ( 0 <= y && y < height_ );
}

bool World::isValidPosition(const Geo::Point& p) const
{
    return isValidPosition( static_cast<int>(p.x()), static_cast<int>(p.y()) );
}

void World::getDimension(int* w, int* h) const
{
    if(w == NULL || h == NULL)
        return;

    *w = this->width_;
    *h = this->height_;
}

int World::getMaxLength() const
{
    return static_cast<int>( Geo::Point(width_, height_).length() );
}
