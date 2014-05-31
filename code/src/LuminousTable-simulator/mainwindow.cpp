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
    mIndexBehavior = 0;
    //mBeahaviours.append(new SimulatorBehaviorRandomDot());
    //mBeahaviours.append(new SimulatorBehaviorDarkSky());
    beahavior = new SimulatorBehaviorRandomDot();




    // Main
    mMainWidget = new QWidget();
    mMainLayout = new QBoxLayout(QBoxLayout::LeftToRight);

    // Matrix
    mMatrixLayout = new QVBoxLayout();
    mMatrixLayout->addWidget(beahavior->getDotMatrix());

    // Inputs
    mButtonA = new QPushButton("Button A");
    connect(mButtonA, SIGNAL(clicked()), this, SLOT(onClickButtonA()));
    mPotentiometer = new QDial();
    mInputsLayout = new QVBoxLayout();
    mInputsLayout->addWidget(mButtonA);
    mInputsLayout->addWidget((mPotentiometer));

    // Central widget
    mMainLayout->addLayout(mMatrixLayout);
    mMainLayout->addLayout(mInputsLayout);
    mMainWidget->setLayout(mMainLayout);
    this->setCentralWidget(mMainWidget);
}

MainWindow::~MainWindow()
{

}


void MainWindow::onClickButtonA()
{
    mMatrixLayout->removeWidget(beahavior->getDotMatrix());
    delete beahavior;

    mIndexBehavior++;
    if (mIndexBehavior > 1){
        mIndexBehavior = 0;
    }

    switch (mIndexBehavior) {
    case 0:
        beahavior = new SimulatorBehaviorRandomDot();
        break;
    case 1:
        beahavior = new SimulatorBehaviorDarkSky();
        break;
    default:
        break;
    }


    mMatrixLayout->addWidget(beahavior->getDotMatrix());
}
