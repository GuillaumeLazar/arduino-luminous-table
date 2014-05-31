#ifndef SIMULATORBEHAVIORRANDOMDOT_H
#define SIMULATORBEHAVIORRANDOMDOT_H

#include "abstractsimulatorbehavior.h"

class SimulatorBehaviorRandomDot : public AbstractSimulatorBehavior
{
    Q_OBJECT
public:
    explicit SimulatorBehaviorRandomDot(QWidget *parent = 0);

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

     int dotCounter;
};

#endif // SIMULATORBEHAVIORRANDOMDOT_H
