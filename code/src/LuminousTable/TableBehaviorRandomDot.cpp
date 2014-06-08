#include "TableBehaviorRandomDot.h"


TableBehaviorRandomDot::TableBehaviorRandomDot()
{
  randomSeed(analogRead(5));

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
}

void TableBehaviorRandomDot::onClickButtonB()
{
  currentColor = arrayColor[random(COLOR_COUNT)];
  dotCounter = 0;
}

void TableBehaviorRandomDot::doLoop()
{
    // pick up a random coordinates
    int x = random(20);
    int y = random(10);

    // set color and show it!
    setCorrectColor(x, y, currentColor);
    FastLED.show();

    // read any changes on Potentiometer and Button B
    readInputs();

    //check auto change mode
    if (dotCounter > 250){
        currentColor = arrayColor[random(COLOR_COUNT)];
        dotCounter = 0;
    }else{
        dotCounter ++;
    }
}

