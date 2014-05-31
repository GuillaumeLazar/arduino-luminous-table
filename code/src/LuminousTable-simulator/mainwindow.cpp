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
    mPotentiometer->setMinimum(0);
    mPotentiometer->setMaximum(255);
    mPotentiometer->setValue(128);
    connect(mPotentiometer, SIGNAL(valueChanged(int)), this, SLOT(onPotentionmeterChanged(int)));

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

    beahavior->getDotMatrix()->setIntensity(mPotentiometer->value());
    mMatrixLayout->addWidget(beahavior->getDotMatrix());
}

void MainWindow::onPotentionmeterChanged(int value)
{
    beahavior->getDotMatrix()->setIntensity(value);
}
