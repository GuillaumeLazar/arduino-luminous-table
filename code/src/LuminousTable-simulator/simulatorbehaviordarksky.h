#ifndef SIMULATORBEHAVIORDARKSKY_H
#define SIMULATORBEHAVIORDARKSKY_H

#include "abstractsimulatorbehavior.h"

class SimulatorBehaviorDarkSky : public AbstractSimulatorBehavior
{
    Q_OBJECT
public:
    explicit SimulatorBehaviorDarkSky(QWidget *parent = 0);

    virtual void onClickButtonB();

protected:
    virtual void init();

protected slots:
    virtual void loop();

private:
    // Simulator beahvior variables
#define STARS_COUNT 20

    int arrayColorIndex;
    int starsPosition[STARS_COUNT][4];
};

#endif // SIMULATORBEHAVIORDARKSKY_H
