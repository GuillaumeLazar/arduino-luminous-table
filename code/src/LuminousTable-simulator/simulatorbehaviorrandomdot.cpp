#include "simulatorbehaviorrandomdot.h"

SimulatorBehaviorRandomDot::SimulatorBehaviorRandomDot(QWidget *parent) :
    AbstractSimulatorBehavior(parent)
{
    this->init();
    this->startLoop();
}

void SimulatorBehaviorRandomDot::init()
{
    //randomSeed(analogRead(5));

    //buttonBValue = 0;
    //tableSubMode = 0;
    dotCounter = 0;

    arrayColor[0] = CRGB::DeepPink;
    arrayColor[1] = CRGB::Red;
    arrayColor[2] = CRGB::Green;
    arrayColor[3] = CRGB::Blue;
    arrayColor[4] = CRGB::Purple;
    arrayColor[5] = CRGB::Yellow;
    arrayColor[6] = CRGB::Cyan;
    arrayColor[7] = CRGB::White;
    arrayColor[8] = CRGB::Chocolate;

    currentColor = arrayColor[random(COLOR_COUNT)];

    paintAll(CRGB::Black, false);
}

void SimulatorBehaviorRandomDot::loop()
{
    // pick up a random coordinates
    int x = random(20);
    int y = random(10);

    // set color and show it!
    setCorrectColor(x, y, currentColor);
    FastLED.show();

    // read any changes on Potentiometer and Button B
    readPotentiometerAndButton();

    //check auto change mode
    if (dotCounter > 250){
        currentColor = arrayColor[random(COLOR_COUNT)];
        dotCounter = 0;
    }else{
        dotCounter ++;
    }
}
