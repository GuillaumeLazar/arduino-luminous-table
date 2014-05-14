#include "abstractsimulatorbehavior.h"

#include <QThread>

AbstractSimulatorBehavior::AbstractSimulatorBehavior(QWidget *parent)
{
    mTimer = new QTimer(this);
    QColor backgroundColor = QColor::fromRgb(150, 150, 150);
    mDotMatrix = new QDotMatrix(parent, 20, 10, backgroundColor);

    connect(mTimer, SIGNAL(timeout()), this, SLOT(loop()));

    FastLED.dotMatrix = mDotMatrix;


}

void AbstractSimulatorBehavior::startLoop()
{
    // TODO: Check Arduino main loop ~10ms?
    mTimer->start(10);
}

QDotMatrix* AbstractSimulatorBehavior::getDotMatrix()
{
    return this->mDotMatrix;
}

int AbstractSimulatorBehavior::random(int high)
{
    int low = 0;
    return qrand() % (high - low) + low;
}

void AbstractSimulatorBehavior::delay(int milliseconds)
{
    QThread::msleep(milliseconds);
}

void AbstractSimulatorBehavior::readPotentiometerAndButton()
{
    delay(5 * 10);
}

void AbstractSimulatorBehavior::setCorrectColor(int x, int y, CRGB currentColor)
{
    //(*leds)[(*ledMatrix)[x][y]] = correctColor(x, color);
    mDotMatrix->setColor(x, y, currentColor);
}

void AbstractSimulatorBehavior::paintAll(CRGB color, boolean forceRefresh)
{

    for(int i=0; i < X_MAX; i++){
        for(int j=0; j < Y_MAX; j++){

            //(*leds)[(*ledMatrix)[i][j]] = correctColor(i, color);
            setCorrectColor(i, j, color);

        }
    }

    if (forceRefresh){
        FastLED.show();
    }
}
