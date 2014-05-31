#ifndef SIMULATORBEHAVIORUNICOLOR_H
#define SIMULATORBEHAVIORUNICOLOR_H

#include "abstractsimulatorbehavior.h"

class SimulatorBehaviorUniColor : public AbstractSimulatorBehavior
{
    Q_OBJECT
public:
    explicit SimulatorBehaviorUniColor(QWidget *parent = 0);

    virtual void onClickButtonB();

protected:
    virtual void init();

protected slots:
    virtual void loop();

private:
    // Simulator beahvior variables
    #define COLOR_COUNT 9

     void setDotColor(int red, int green, int blue);

     CRGB currentColor;
     CRGB arrayColor[COLOR_COUNT];

     int arrayColorIndex;
};

#endif // SIMULATORBEHAVIORUNICOLOR_H
