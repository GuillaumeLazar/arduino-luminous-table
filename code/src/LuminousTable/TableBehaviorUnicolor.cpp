#include "TableBehaviorUnicolor.h"


TableBehaviorUnicolor::TableBehaviorUnicolor()
{
  buttonBValue = 0;
  tableSubMode = 0;

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

void TableBehaviorUnicolor::readButtonBValue()
{

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
      arrayColorIndex++;
      arrayColorIndex = arrayColorIndex % COLOR_COUNT;
      currentColor = arrayColor[arrayColorIndex];
      paintAll(currentColor);

    }
  }
}


void TableBehaviorUnicolor::setDotColor(int red, int green, int blue)
{
  currentColor.r = red;
  currentColor.g = green;
  currentColor.b = blue;

}

void TableBehaviorUnicolor::doLoop()
{
  paintAll(currentColor);

  int i = 0;
  while(i < 5){
    delay(10);
    readPotentiometerValue();
    readButtonBValue();
    i++; 
  }
}

void TableBehaviorUnicolor::paintAll(CRGB color)
{

  for(int i=0; i < X_MAX; i++){
    for(int j=0; j < Y_MAX; j++){
      (*leds)[(*ledMatrix)[i][j]] = correctColor(i, color);
    }
  }
  FastLED.show(); 
}

