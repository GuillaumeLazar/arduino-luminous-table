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

protected:
    void startLoop();
    void paintAll(CRGB color, bool forceRefresh);

    int random(int high);
    void delay(int milliseconds);
    void readPotentiometerAndButton();
    void setCorrectColor(int x, int y, CRGB currentColor);

    virtual void init() = 0;

    QDotMatrix *mDotMatrix;
    QTimer *mTimer;
    FakeFastLED FastLED;

protected slots:
    virtual void loop() = 0;
};

#endif // ABSTRACTSIMULATORBEHAVIOR_H
