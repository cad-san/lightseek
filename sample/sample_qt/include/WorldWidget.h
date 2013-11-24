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

    QSize sizeHint() const;

public slots:
    void init();
    void start();
    void stop();
    void onTimer();

private:
    WorldPtr world_model_;
    RobotPtr robot_model_;

    QTimer* timer_;

protected:
    void paintEvent(QPaintEvent* event);

private:
    void paintField(QPainter& painter);
    void paintObjects(QPainter& painter);
    void paintRobot(QPainter& painter);
};

#endif
