#ifndef SIMULATORBEHAVIORDARKSKY_H
#define SIMULATORBEHAVIORDARKSKY_H

#include "abstractsimulatorbehavior.h"

class SimulatorBehaviorDarkSky : public AbstractSimulatorBehavior
{
    Q_OBJECT
public:
    explicit SimulatorBehaviorDarkSky(QWidget *parent = 0);

protected:
    virtual void init();

protected slots:
    virtual void loop();

private:
    // Simulator beahvior variables
#define COLOR_COUNT 9
#define STARS_COUNT 5

    CRGB currentColor;
    CRGB arrayColor[COLOR_COUNT];

    int arrayColorIndex;
    int starsPosition[STARS_COUNT][4];
};

#endif // SIMULATORBEHAVIORDARKSKY_H
