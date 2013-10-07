#ifndef D_ACTION_H
#define D_ACTION_H

#include <boost/shared_ptr.hpp>

class Action
{
public:
    Action() {}
    virtual ~Action() {}

    virtual bool moveFront(const int speed) = 0;
    virtual bool rotate(const int angle) = 0;
};

typedef boost::shared_ptr<Action> ActionPtr;

#endif
