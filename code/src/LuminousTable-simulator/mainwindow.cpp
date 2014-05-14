#include "mainwindow.h"

#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    mTimer = new QTimer(this);
    mDotMatrix = new QDotMatrix(this, 20, 10);

    connect(mTimer, SIGNAL(timeout()), this, SLOT(loop()));
    setCentralWidget(mDotMatrix);

    this->init();
    FastLED.dotMatrix = mDotMatrix;

    // TODO: Check Arduino main loop ~10ms?
    mTimer->start(10);
}

MainWindow::~MainWindow()
{

}

int MainWindow::random(int high)
{
    int low = 0;
    return qrand() % (high - low) + low;
}

void MainWindow::delay(int milliseconds)
{
    QThread::msleep(milliseconds);
}


#define COLOR_COUNT 9
CRGB currentColor;
CRGB arrayColor[COLOR_COUNT];
int dotCounter = 0;

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

void MainWindow::loop()
{

    int x = random(20);
    int y = random(10);

     //(*leds)[(*ledMatrix)[x][y]] = correctColor(x, currentColor);
     mDotMatrix->setColor(x, y, currentColor);
     dotCounter ++;

     FastLED.show();

     //int i = 0;
     //while(i < 5){
     //  delay(10);
     //  readPotentiometerValue();
     //  readButtonBValue();
     //  i++;
     //}
     delay(5 * 10);

     //check auto change mode
     if (dotCounter > 250){
       currentColor = arrayColor[random(COLOR_COUNT)];
       dotCounter = 0;
     }
}
