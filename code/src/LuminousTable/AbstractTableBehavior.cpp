#include "AbstractTableBehavior.h"


void AbstractTableBehavior::doBlack()
{
  for(int i=0; i < X_MAX; i++){
    for(int j=0; j < Y_MAX; j++){  
      (*leds)[(*ledMatrix)[i][j]] = correctColor(i, CRGB::Black);
    }
  }

  FastLED.show();
}

void AbstractTableBehavior::doSetup()
{
  //LEDS.setBrightness(128);
  readPotentiometerValue();

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

void AbstractTableBehavior::readPotentiometerValue()
{
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


