#ifndef D_MAIN_WINDOW_H
#define D_MAIN_WINDOW_H

#include <QMainWindow>
#include "WorldWidget.h"
#include "Environment.h"
#include "Thread.h"

typedef boost::shared_ptr<Environment> EnvironmentPtr;
typedef boost::shared_ptr<Thread> AgentPtr;

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();

    void setWorldModel(const WorldPtr& world_ptr);
    void setRobotModel(const RobotPtr& robot_ptr);

    void setEnvironment(const EnvironmentPtr& env_ptr);
    void setAgent(const AgentPtr& agent_ptr);

private:
    void createWidgets();
    void createActions();
    void createToolBars();

private slots:
    void init();
    void start();
    void stop();

private:
    WorldWidget *world_widget_;
    EnvironmentPtr env_;
    AgentPtr agent_;

    QAction* init_act_;
    QAction* start_act_;
    QAction* stop_act_;
};

#endif
