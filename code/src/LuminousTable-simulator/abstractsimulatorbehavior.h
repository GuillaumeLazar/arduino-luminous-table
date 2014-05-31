#ifndef ABSTRACTSIMULATORBEHAVIOR_H
#define ABSTRACTSIMULATORBEHAVIOR_H

#include <QTimer>

#include "qdotmatrix.h"
#include "FakeHardware.h"

//TODO: put this in member variable!
#define X_MAX 20
#define Y_MAX 10

class AbstractSimulatorBehavior : public QObject
{
    Q_OBJECT

    struct FakeFastLED {
        QDotMatrix *dotMatrix;
        void show()
        {
            dotMatrix->update();
        }
    };

public:
    AbstractSimulatorBehavior(QWidget *parent = 0);
    ~AbstractSimulatorBehavior();

    QDotMatrix *getDotMatrix();
    void setBrightness(int intensity);

    virtual void onClickButtonB() { }

protected:
    void startLoop();
    void paintAll(CRGB color, bool forceRefresh);

    int analogRead(int port) { return 0; }
    void randomSeed(int seed);
    int random(int high);
    void delay(int milliseconds);

    virtual void init() = 0;

    void readInputs();
    void setCorrectColor(int x, int y, CRGB currentColor);

    QDotMatrix *mDotMatrix;
    QTimer *mTimer;
    FakeFastLED FastLED;

protected slots:
    virtual void loop() = 0;
};

#endif // ABSTRACTSIMULATORBEHAVIOR_H
