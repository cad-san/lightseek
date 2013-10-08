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
    return ( this->x_ <= x && x < this->x_ + this->width_  ) &&
           ( this->y_ <= y && y < this->y_ + this->height_ );
}

bool SquareObstacle::isInArea(const Geo::Point& p) const
{
    return isInArea( static_cast<int>(p.x()), static_cast<int>(p.y()) );
}

bool SquareObstacle::isInArea(const Obstacle& obstacle) const
{
    bool in_area_flag = false;
    std::vector<Geo::Point> vertex_list = getVertexList();

    for(unsigned int i = 0; i < vertex_list.size(); i++)
        in_area_flag |= obstacle.isInArea(vertex_list.at(i));

    return in_area_flag;
}

std::vector<Geo::Point> SquareObstacle::getVertexList() const
{
    std::vector<Geo::Point> vertex_list;

    Geo::Point min = getMinPoint();
    Geo::Point max = getMaxPoint();

    // 各辺の生成に利用するため、頂点は隣り合う順で追加する
    vertex_list.push_back( Geo::Point(min.x(), min.y()) );
    vertex_list.push_back( Geo::Point(min.x(), max.y()) );
    vertex_list.push_back( Geo::Point(max.x(), max.y()) );
    vertex_list.push_back( Geo::Point(max.x(), min.y()) );

    return vertex_list;
}

std::vector<Geo::Line> SquareObstacle::getEdgeList() const
{
    std::vector<Geo::Line> edge_list;
    std::vector<Geo::Point> vertex_list = getVertexList();

    for(unsigned int i = 0; i < vertex_list.size(); i++)
    {
        Geo::Point s = vertex_list.at(i);
        Geo::Point e = vertex_list.at((i + 1) % vertex_list.size());

        edge_list.push_back(Geo::Line(s, e));
    }

    return edge_list;
}

int SquareObstacle::getDistance(int x, int y, int angle) const
{
    int min_dist = World::INVALID_DISTANCE;

    Geo::Point src = Geo::Point(x, y);
    Geo::Line line = Geo::Line( src, 1.0, Geo::convert_radian(angle) );
    double radian = line.angle();

    std::vector<Geo::Line> edge_list = getEdgeList();

    for(unsigned int i = 0; i < edge_list.size(); i++)
    {
        Geo::Line edge = edge_list.at(i);

        if(!Geo::intersects_l(edge, line))
            continue;

        Geo::Point tgt = Geo::intersection_l(edge, line);

        if(!isInArea(tgt))
            continue;

        if(!Geo::equals(radian, Geo::angle(src, tgt)))
            continue;

        int distance = static_cast<int>(Geo::distance(src, tgt));

        if( min_dist == World::INVALID_DISTANCE || distance < min_dist)
            min_dist = distance;
    }

    return min_dist;
}
