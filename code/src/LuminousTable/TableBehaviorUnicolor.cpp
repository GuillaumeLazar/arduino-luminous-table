#include "TableBehaviorUnicolor.h"


TableBehaviorUnicolor::TableBehaviorUnicolor()
{
  arrayColor[0] = CRGB::White;
    arrayColor[1] = CRGB::Red;
    arrayColor[2] = CRGB::Green;
    arrayColor[3] = CRGB::Blue;
    arrayColor[4] = CRGB::Purple;
    arrayColor[5] = CRGB::Yellow;
    arrayColor[6] = CRGB::Cyan;
    arrayColor[7] = CRGB::DeepPink;
    arrayColor[8] = CRGB::Chocolate;

    arrayColorIndex = 0;
    currentColor = arrayColor[arrayColorIndex];
}

void TableBehaviorUnicolor::onClickButtonB()
{
    arrayColorIndex++;
    arrayColorIndex = arrayColorIndex % COLOR_COUNT;
    currentColor = arrayColor[arrayColorIndex];
    //paintAll(currentColor, true);
}

void TableBehaviorUnicolor::doLoop()
{
     paintAll(currentColor, true);

    // read any changes on Potentiometer and Button B
    readInputs();
}
