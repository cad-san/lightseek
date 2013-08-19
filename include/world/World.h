#ifndef D_WORLD_H
#define D_WORLD_H

#include <boost/shared_ptr.hpp>

class World
{
private:
    int width;
    int height;
public:
    static const int INVALID_COORD = -1;
    static const int INVALID_DISTANCE = -1;

    World();
    World(int width, int height);
    virtual ~World();

    virtual int getDistance(int x, int y, double angle) const;
    virtual bool isValidPosition(int x, int y) const;
};

typedef boost::shared_ptr<World> WorldPtr;

#endif
