#include "TableBehaviorVUmeter.h"


TableBehaviorVUmeter::TableBehaviorVUmeter()
{
    currentSoundLevel = 0;
    currentTopBarLevel = 0;
    currentTopBarLevelCpt = 0;
}

void TableBehaviorVUmeter::onClickButtonB()
{
    paintAll(CRGB::Black, false);
}

void TableBehaviorVUmeter::doLoop()
{
    paintAll(CRGB::Black, false);

    CRGB color;

    if (currentSoundLevel < mSoundLevel){
        currentSoundLevel++;
    }else if (currentSoundLevel > mSoundLevel){
        currentSoundLevel--;
    }

    if (currentSoundLevel < 1){
        currentSoundLevel = 1;
    }


    if (currentTopBarLevel <= currentSoundLevel){
        currentTopBarLevel = currentSoundLevel;

    }else if (currentTopBarLevel > currentSoundLevel){
        currentTopBarLevelCpt++;

        if (currentTopBarLevelCpt > 3){
            currentTopBarLevelCpt = 0;
            currentTopBarLevel--;
        }
    }

    //draw body
    for(int i=0; i < currentSoundLevel ; i++){
        color.g = 200 - i*10;
        color.r = 200 - color.g;
        color.b = 0;

        for(int y=0; y < Y_MAX ; y++){
            setCorrectColor(X_MAX-1-i, y, color);
        }
    }

    //draw top bar
    if (currentTopBarLevel > 0){
        for(int y=0; y < Y_MAX ; y++){
            setCorrectColor(X_MAX-currentTopBarLevel, y, color);
        }
    }


    FastLED.show();


    // read any changes on Potentiometer, Button B and Sound level
    readInputs();
}
