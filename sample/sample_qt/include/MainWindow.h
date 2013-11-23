#ifndef D_MAIN_WINDOW_H
#define D_MAIN_WINDOW_H

#include <QMainWindow>
#include "WorldWidget.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();

    void setWorldModel(const WorldPtr& world_ptr);
    void setRobotModel(const RobotPtr& robot_ptr);

private:
    void createWidgets();

private:
    WorldWidget *world_widget_;
};

#endif
