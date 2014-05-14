#ifndef SIMULATORBEHAVIORRANDOMDOT_H
#define SIMULATORBEHAVIORRANDOMDOT_H

#include "abstractsimulatorbehavior.h"

class SimulatorBehaviorRandomDot : public AbstractSimulatorBehavior
{
    Q_OBJECT
public:
    explicit SimulatorBehaviorRandomDot(QWidget *parent = 0);

protected:
    virtual void init();

protected slots:
    virtual void loop();

private:
    // Simulator beahvior variables
#define COLOR_COUNT 9
    CRGB currentColor;
    CRGB arrayColor[COLOR_COUNT];
    int dotCounter = 0;

};

#endif // SIMULATORBEHAVIORRANDOMDOT_H
