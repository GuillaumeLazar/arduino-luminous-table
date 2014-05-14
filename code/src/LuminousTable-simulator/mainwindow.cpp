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
    //mAbstractSimulatorBehavior = new SimulatorBehaviorRandomDot(this);
    mAbstractSimulatorBehavior = new SimulatorBehaviorDarkSky(this);

    setCentralWidget(mAbstractSimulatorBehavior->getDotMatrix());
}

MainWindow::~MainWindow()
{

}

//---------------------------------------------------------------------------------
// SIMULATOR SANDBOX
//---------------------------------------------------------------------------------

/*
// Simulator beahvior variables
#define COLOR_COUNT 9
CRGB currentColor;
CRGB arrayColor[COLOR_COUNT];
int dotCounter = 0;

// Simulator function : init()
void MainWindow::init()
{
    arrayColor[0] = CRGB::DeepPink;
    arrayColor[1] = CRGB::Red;
    arrayColor[2] = CRGB::Green;
    arrayColor[3] = CRGB::Blue;
    arrayColor[4] = CRGB::Purple;
    arrayColor[5] = CRGB::Yellow;
    arrayColor[6] = CRGB::Cyan;
    arrayColor[7] = CRGB::White;
    arrayColor[8] = CRGB::Chocolate;

    currentColor = arrayColor[0];
}

// Simulator function : loop()
void MainWindow::loop()
{
    // pick up a random coordinates
    int x = random(20);
    int y = random(10);

    // set color and show it!
    setCorrectColor(x, y, currentColor);
    FastLED.show();

    // read any changes on Potentiometer and Button B
    readPotentiometerAndButton();

    //check auto change mode
    if (dotCounter > 250){
        currentColor = arrayColor[random(COLOR_COUNT)];
        dotCounter = 0;
    }else{
        dotCounter ++;
    }
}
*/
