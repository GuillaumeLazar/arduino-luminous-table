#ifndef AbstractTableBehavior_H
#define AbstractTableBehavior_H

#include <QTimer>

#include "qdotmatrix.h"
#include "FakeHardware.h"

//TODO: put this in member variable!
#define X_MAX 20
#define Y_MAX 10

class AbstractTableBehavior : public QObject
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
    AbstractTableBehavior(QWidget *parent = 0);
    virtual ~AbstractTableBehavior();

    QDotMatrix *getDotMatrix();
    void startLoop();
    void setBrightness(int intensity);
    void setSoundLevel(int level);
    void paintAll(CRGB color, bool forceRefresh);
    virtual void onClickButtonB() { }

protected:



    int analogRead(int port) { return 0; }
    void randomSeed(int seed);
    int random(int high);
    void delay(int milliseconds);

    //virtual void init() = 0;

    void readInputs();
    void setCorrectColor(int x, int y, CRGB currentColor);
    void drawSquare(int x, int y, int size, CRGB color);

    QDotMatrix *mDotMatrix;
    QTimer *mTimer;
    FakeFastLED FastLED;

    int mSoundLevel;

protected slots:
    virtual void doLoop() = 0;
};

#endif // AbstractTableBehavior_H
