#include "TableBehaviorPixelart.h"


TableBehaviorPixelart::TableBehaviorPixelart()
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

void TableBehaviorPixelart::onClickButtonB()
{
    arrayColorIndex++;
    arrayColorIndex = arrayColorIndex % COLOR_COUNT;
    currentColor = arrayColor[arrayColorIndex];
    //paintAll(currentColor, true);
}

void TableBehaviorPixelart::doLoop()
{
    paintAll(CRGB::Black, false);

    int posX = 4;
    int posY = 1;

    setCorrectColor(posX+2, posY, currentColor);
    setCorrectColor(posX+8, posY, currentColor);

    setCorrectColor(posX+3, posY+1, currentColor);
    setCorrectColor(posX+7, posY+1, currentColor);

    for (int i=posX+2; i < posX+9; i++)
        setCorrectColor(i,  posY+2, currentColor);

    setCorrectColor(posX+1, posY+3, currentColor);
    setCorrectColor(posX+2, posY+3, currentColor);
    setCorrectColor(posX+4, posY+3, currentColor);
    setCorrectColor(posX+5, posY+3, currentColor);
    setCorrectColor(posX+6, posY+3, currentColor);
    setCorrectColor(posX+8, posY+3, currentColor);
    setCorrectColor(posX+9, posY+3, currentColor);

    for (int i=posX; i < posX+11; i++)
        setCorrectColor(i, posY+4, currentColor);

    for (int i=posX; i < posX+11; i++){
        if(i != posX+1 && i != posX+9)
            setCorrectColor(i, posY+5, currentColor);
    }

    setCorrectColor(posX, posY+6, currentColor);
    setCorrectColor(posX+2, posY+6, currentColor);
    setCorrectColor(posX+8, posY+6, currentColor);
    setCorrectColor(posX+10, posY+6, currentColor);

    setCorrectColor(posX+3, posY+7, currentColor);
    setCorrectColor(posX+4, posY+7, currentColor);

    setCorrectColor(posX+6, posY+7, currentColor);
    setCorrectColor(posX+7, posY+7, currentColor);



    FastLED.show();


    // read any changes on Potentiometer and Button B
    readInputs();
}
