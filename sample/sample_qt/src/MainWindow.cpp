#include "MainWindow.h"

MainWindow::MainWindow()
{
    createWidgets();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createWidgets()
{
    world_widget_ = new WorldWidget(this);
    setCentralWidget(world_widget_);
}
