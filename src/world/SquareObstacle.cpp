#include "SquareObstacle.h"
#include "World.h"

static const Geo::Point INVALID_POINT(World::INVALID_COORD, World::INVALID_COORD);

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

Geo::Line SquareObstacle::getEdge(int index) const
{
    if(index < 0 || index >= 4)
        return Geo::Line(INVALID_POINT, INVALID_POINT);

    Geo::Line edges[4];
    Geo::Point s = getMinPoint();
    Geo::Point e = getMaxPoint();

    edges[0] = Geo::Line(e.x(), s.y(), e.x(), e.y());     // 右
    edges[1] = Geo::Line(s.x(), e.y(), e.x(), e.y());     // 下
    edges[2] = Geo::Line(s.x(), s.y(), s.x(), e.y());     // 左
    edges[3] = Geo::Line(s.x(), s.y(), e.x(), s.y());     // 上

    return edges[index];
}

int SquareObstacle::getDistance(int x, int y, double angle) const
{
    int min_dist = World::INVALID_DISTANCE;

    Geo::Point src = Geo::Point(x, y);
    Geo::Line line = Geo::Line( src, 1.0, Geo::convert_radian(angle) );

    for(unsigned int i = 0; i < 4; i++)
    {
        Geo::Line edge = getEdge(i);

        if(!Geo::intersects_l(edge, line))
            continue;

        Geo::Point tgt = Geo::intersection_l(edge, line);

        if(!isInArea(tgt.x(), tgt.y()))
            continue;

        int distance = Geo::distance(src, tgt);

        if( min_dist == World::INVALID_DISTANCE || distance < min_dist)
            min_dist = distance;
    }

    return min_dist;
}
