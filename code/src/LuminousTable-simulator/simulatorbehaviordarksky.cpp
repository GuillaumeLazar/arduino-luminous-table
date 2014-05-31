#include "simulatorbehaviordarksky.h"

SimulatorBehaviorDarkSky::SimulatorBehaviorDarkSky(QWidget *parent) :
    AbstractSimulatorBehavior(parent)
{
    this->init();
    this->startLoop();
}

void SimulatorBehaviorDarkSky::init()
{
    //TODO: handle buttonB
    //buttonBValue = 0;
    //tableSubMode = 0;

    for(int i=0; i < STARS_COUNT; i++){
        starsPosition[i][0] = random(X_MAX);
        starsPosition[i][1] = random(Y_MAX);
        starsPosition[i][2] = 0;
        starsPosition[i][3] = 0;
    }
}

void SimulatorBehaviorDarkSky::onClickButtonB()
{
    for(int i=0; i < STARS_COUNT; i++){
        starsPosition[i][0] = random(X_MAX);
        starsPosition[i][1] = random(Y_MAX);
        starsPosition[i][2] = 128;
        starsPosition[i][3] = 128;
    }
}

void SimulatorBehaviorDarkSky::loop()
{
    paintAll(CRGB::Black, false);

    for(int i=0; i < STARS_COUNT; i++){
        int x = starsPosition[i][0];
        int y = starsPosition[i][1];

        CRGB color;
        int speedShine = 6;

        if ( abs(starsPosition[i][2] - starsPosition[i][3]) < speedShine){
            int intensity = random(255);
            starsPosition[i][3] = intensity;

            if(starsPosition[i][2] < 25){
                starsPosition[i][0] = random(X_MAX);
                starsPosition[i][1] = random(Y_MAX);
            }
        }

        if (starsPosition[i][2] > starsPosition[i][3]){

            starsPosition[i][2] = starsPosition[i][2] - speedShine;

            color.r = starsPosition[i][2];
            color.g = starsPosition[i][2];
            color.b = starsPosition[i][2];

        }
        else  if (starsPosition[i][2] < starsPosition[i][3]){

            starsPosition[i][2] = starsPosition[i][2] + speedShine;

            color.r = starsPosition[i][2];
            color.g = starsPosition[i][2];
            color.b = starsPosition[i][2];
        }

        //(*leds)[(*ledMatrix)[x][y]] = correctColor(x, color);
        setCorrectColor(x, y, color);
    }

    FastLED.show();
    //delay(100);

    readInputs();
}
