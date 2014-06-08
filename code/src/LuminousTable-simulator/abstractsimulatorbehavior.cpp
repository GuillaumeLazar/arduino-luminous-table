#include "abstractsimulatorbehavior.h"

#include <QThread>

// QThread::msleep is only public on Qt5...
// Ugly tricks to process a sleep on Qt4
class SleepThread : public QThread {
public:
   static inline void msleep(unsigned long msecs) {
       QThread::msleep(msecs);
   }
};

AbstractSimulatorBehavior::AbstractSimulatorBehavior(QWidget *parent)
{
    mTimer = new QTimer(this);
    mDotMatrix = new QDotMatrix(parent, 20, 10, Qt::black);

    connect(mTimer, SIGNAL(timeout()), this, SLOT(loop()));

    FastLED.dotMatrix = mDotMatrix;
}

AbstractSimulatorBehavior::~AbstractSimulatorBehavior()
{
    delete mDotMatrix;
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

void AbstractSimulatorBehavior::randomSeed(int seed)
{
    //TODO: use the seed!
}

void AbstractSimulatorBehavior::delay(int milliseconds)
{
    SleepThread::msleep(milliseconds);
}

void AbstractSimulatorBehavior::readInputs()
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

void AbstractSimulatorBehavior::setBrightness(int intensity)
{
    mDotMatrix->setIntensity(intensity);
}
