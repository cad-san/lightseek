#ifndef D_WORLD_H
#define D_WORLD_H

#include <boost/shared_ptr.hpp>

class World
{
public:
    static const int INVALID_COORD = -1;
    static const int INVALID_DISTANCE = -1;

    virtual ~World() {};

    virtual int getDistance(int x, int y, double angle) const = 0;
};

typedef boost::shared_ptr<World> WorldPtr;

#endif
