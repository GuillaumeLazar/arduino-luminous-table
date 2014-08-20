#include "TableBehaviorRandomDotSound.h"


TableBehaviorRandomDotSound::TableBehaviorRandomDotSound()
{
    currentIndex = 0;
    localSoundLevel = 0;
}

void TableBehaviorRandomDotSound::onClickButtonB()
{
    paintAll(CRGB::Black, false);
}

void TableBehaviorRandomDotSound::doLoop()
{
    // pick up a random coordinates
    int x = random(20);
    int y = random(10);

    CRGB color;
    if (mSoundLevel > 0){
        color.g = 200 - mSoundLevel*10;
        color.r = 200 - color.g;
        color.b = 0;
    }else{
        color = CRGB::Black;
    }

    int size = mSoundLevel/2;
    if (size < 1){ size = 1; }
    drawSquare(x, y, size, color);

    FastLED.show();

    // read any changes on Potentiometer and Button B
    readInputs();
}
