#include "mainwindow.h"

#include <QDebug>
#include <QColor>

#include "simulatorbehaviorrandomdot.h"
#include "simulatorbehaviordarksky.h"

//---------------------------------------------------------------------------------
// SIMULATOR INITIALIZATION
//---------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mAbstractSimulatorBehavior = new SimulatorBehaviorRandomDot(this);
    //mAbstractSimulatorBehavior = new SimulatorBehaviorDarkSky(this);

    setCentralWidget(mAbstractSimulatorBehavior->getDotMatrix());
}

MainWindow::~MainWindow()
{

}
