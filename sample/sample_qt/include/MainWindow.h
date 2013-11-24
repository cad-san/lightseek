#ifndef D_MAIN_WINDOW_H
#define D_MAIN_WINDOW_H

#include <QMainWindow>
#include "WorldWidget.h"
#include "Environment.h"

typedef boost::shared_ptr<Environment> EnvironmentPtr;

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();

    void setWorldModel(const WorldPtr& world_ptr);
    void setRobotModel(const RobotPtr& robot_ptr);

    void setEnvironment(const EnvironmentPtr& env_ptr);

private:
    void createWidgets();

private slots:
    void init();
    void start();
    void stop();

private:
    WorldWidget *world_widget_;
    EnvironmentPtr env_;
};

#endif
