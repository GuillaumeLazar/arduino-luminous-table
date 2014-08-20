#include "TableBehaviorVUmeterB.h"


TableBehaviorVUmeterB::TableBehaviorVUmeterB()
{
    currentIndex = 0;
    localSoundLevel = 0;
}

void TableBehaviorVUmeterB::onClickButtonB()
{
    paintAll(CRGB::Black, false);
}

void TableBehaviorVUmeterB::doLoop()
{
    //paintAll(CRGB::Black, false);

    localSoundLevel = mSoundLevel / 2;

    //draw current sound level
    CRGB color;


    for(int y=0; y < Y_MAX ; y++){
        int posY = Y_MAX - y -1;

        if (y < localSoundLevel){
            color.g = 200 - y*20;
            color.r = 200 - color.g;
            color.b = 0;
        }else{
            color = CRGB::Black;
        }

        setCorrectColor(currentIndex, posY, color);
    }

    FastLED.show();

    currentIndex++;
    if(currentIndex == X_MAX){
        currentIndex = 0;
    }

    // read any changes on Potentiometer, Button B and Sound level
    readInputs();
}
