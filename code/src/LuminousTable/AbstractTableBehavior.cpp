#include "AbstractTableBehavior.h"


void AbstractTableBehavior::doSetup()
{
  //LEDS.setBrightness(128);
  readInputs();

  FastLED.addLeds<WS2812, DATA_PIN, RGB>((*leds), NUM_LEDS);

  initLedMatrix(); 
}

void AbstractTableBehavior::initLedMatrix()
{
  int isReverted = 0;
  int count = 0;

  for(int x = 0; x < X_MAX; x++){ 

    if (isReverted == 0){
      for(int y = 0; y < Y_MAX; y++){ 
        (*ledMatrix)[x][y] = count;//&leds[count];
        //serialPrintf("ledMatrix[%d][%d]=%d\n", x, y, ledMatrix[x][y]);
        count++;
      }

    }
    else if (isReverted == 1){
      for(int y = Y_MAX-1; y >= 0; y--){ 
        (*ledMatrix)[x][y] = count; //&leds[count];
        //serialPrintf("ledMatrix[%d][%d]=%d\n", x, y, ledMatrix[x][y]);


        count++;
      }
    }

    isReverted = 1 - isReverted;
  }

  //serialPrintf("count=%d\n", count);
}

void AbstractTableBehavior::readInputs()
{
  
  int i = 0;
  while(i < 1){
    delay(10);
    i++; 
  
    //invert pot value
    int potReadValue = 1023 - analogRead(POT_PIN);
    int diffValue = potReadValue - potValue;
  
    if (potReadValue != potValue && (abs(diffValue) > 5) ){
      potValue = potReadValue;
      newBrightness = potValue >> 2; //fast division by 4
      LEDS.setBrightness(newBrightness);
      FastLED.show();
      //serialPrintf("pot = %d\n", potValue);
      //serialPrintf("newBrightness = %d\n", newBrightness);
    }
    
    
    
    int val = digitalRead(BUTTON_B_PIN);  // read input value
    if (val != buttonBValue){
      buttonBValue = val;
      //serialPrintf("button B = %d\n", buttonBValue);
  
      if (buttonBValue == HIGH){
        int noteDuration = 200;
        tone(SPEAKER_PIN, NOTE_D5, noteDuration);
        delay(noteDuration);
        noTone(SPEAKER_PIN);
  
      }
      else{
        onClickButtonB();
      }
    }
  }

}

CRGB AbstractTableBehavior::correctColor(int cols, CRGB color)
{
  CRGB colorCorrected;
  
  
  if (cols < 10){
    colorCorrected.r = 0.8f * color.r;
    colorCorrected.g = 0.8f * color.g;
    colorCorrected.b = 0.8f * color.b;
  }
  else{
    colorCorrected.r = 0.7f * color.r;
    colorCorrected.g = 1.0f * color.g;
    colorCorrected.b = 0.6f * color.b;
  }

  return colorCorrected;
}

void AbstractTableBehavior::setCorrectColor(int x, int y, CRGB currentColor)
{
    (*leds)[(*ledMatrix)[x][y]] = correctColor(x, currentColor);
    //mDotMatrix->setColor(x, y, currentColor);
}

void AbstractTableBehavior::paintAll(CRGB color, boolean forceRefresh)
{

    for(int i=0; i < X_MAX; i++){
        for(int j=0; j < Y_MAX; j++){

            //(*leds)[(*ledMatrix)[i][j]] = correctColor(i, color);
            setCorrectColor(i, j, color);
        }
    }

    if (forceRefresh){
        FastLED.show();
    }
}


