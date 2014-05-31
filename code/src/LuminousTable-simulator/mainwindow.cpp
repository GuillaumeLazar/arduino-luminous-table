#include "mainwindow.h"

#include <QDebug>
#include <QColor>


#include "simulatorbehaviorrandomdot.h"
#include "simulatorbehaviordarksky.h"
#include "simulatorbehaviorunicolor.h"

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
    mButtonA = new QPushButton("Switch");
    mButtonB = new QPushButton("Action");
    connect(mButtonA, SIGNAL(clicked()), this, SLOT(onClickButtonA()));
    connect(mButtonB, SIGNAL(clicked()), this, SLOT(onClickButtonB()));

    mPotentiometer = new QDial();
    mPotentiometer->setMinimum(0);
    mPotentiometer->setMaximum(255);
    mPotentiometer->setValue(192);
    beahavior->setBrightness(mPotentiometer->value());
    connect(mPotentiometer, SIGNAL(valueChanged(int)), this, SLOT(onPotentionmeterChanged(int)));

    mInputsLayout = new QVBoxLayout();
    mInputsLayout->addWidget(mButtonA);
    mInputsLayout->addWidget(mButtonB);
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
    if (mIndexBehavior > 2){
        mIndexBehavior = 0;
    }

    switch (mIndexBehavior) {
    case 0:
        beahavior = new SimulatorBehaviorRandomDot();
        break;
    case 1:
        beahavior = new SimulatorBehaviorUniColor();
        break;
    case 2:
        beahavior = new SimulatorBehaviorDarkSky();
        break;
    default:
        break;
    }

    beahavior->getDotMatrix()->setIntensity(mPotentiometer->value());
    mMatrixLayout->addWidget(beahavior->getDotMatrix());
}

void MainWindow::onClickButtonB()
{
    beahavior->onClickButtonB();
}

void MainWindow::onPotentionmeterChanged(int value)
{
    beahavior->getDotMatrix()->setIntensity(value);
}
