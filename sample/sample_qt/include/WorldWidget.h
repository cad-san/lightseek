#ifndef D_WORLD_WIDGET_H
#define D_WORLD_WIDGET_H

#include <QWidget>
#include "World.h"
#include "Robot.h"

class WorldWidget : public QWidget
{
Q_OBJECT
public:
    WorldWidget(QWidget* parent = 0);
    virtual ~WorldWidget();
    void setWorldModel(const WorldPtr& world_ptr);
    void setRobotModel(const RobotPtr& robot_ptr);

private:
    WorldPtr world_model_;
    RobotPtr robot_model_;
};

#endif
