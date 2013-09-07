#ifndef D_ACTION_H
#define D_ACTION_H

class Action
{
public:
    Action() {};
    virtual ~Action() {};

    virtual bool moveFront(const int speed) = 0;
    virtual bool rotate(const int angle) = 0;
};

#endif
