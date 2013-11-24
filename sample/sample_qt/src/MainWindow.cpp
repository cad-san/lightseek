#include "MainWindow.h"

#include <QtGui>

MainWindow::MainWindow()
{
    createWidgets();
    createActions();
    createToolBars();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createWidgets()
{
    world_widget_ = new WorldWidget(this);
    setCentralWidget(world_widget_);
}

void MainWindow::createActions()
{
    // 初期化
    init_act_ = new QAction(tr("&Init"), this);
    start_act_ = new QAction(tr("&Start"), this);
    stop_act_ = new QAction(tr("&Stop"), this);

    connect( init_act_, SIGNAL(triggered()), this, SLOT( init()));
    connect(start_act_, SIGNAL(triggered()), this, SLOT(start()));
    connect( stop_act_, SIGNAL(triggered()), this, SLOT( stop()));
}

void MainWindow::createToolBars()
{
    QToolBar *robot_control = addToolBar(tr("Robot Control"));
    robot_control->setMovable(false);

    // 右寄せ用の詰め物
    QWidget *spacer_widget = new QWidget(this);
    spacer_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    spacer_widget->setVisible(true);
    robot_control->addWidget(spacer_widget);

    // Actionを登録する
    robot_control->addAction(init_act_);
    robot_control->addAction(start_act_);
    robot_control->addAction(stop_act_);
}

void MainWindow::init()
{
    emit world_widget_->init();

    if(agent_)
        agent_->init();

    if(env_)
        env_->init();
}

void MainWindow::start()
{
    emit world_widget_->start();

    if(agent_)
        agent_->start();

    if(env_)
        env_->start();
}

void MainWindow::stop()
{
    emit world_widget_->stop();

    if(agent_)
        agent_->stop();

    if(env_)
        env_->stop();
}

void MainWindow::setWorldModel(const WorldPtr& world_ptr)
{
    world_widget_->setWorldModel(world_ptr);
}

void MainWindow::setRobotModel(const RobotPtr& robot_ptr)
{
    world_widget_->setRobotModel(robot_ptr);
}

void MainWindow::setEnvironment(const EnvironmentPtr& env_ptr)
{
    env_ = env_ptr;
}

void MainWindow::setAgent(const AgentPtr& agent_ptr)
{
    agent_ = agent_ptr;
}
