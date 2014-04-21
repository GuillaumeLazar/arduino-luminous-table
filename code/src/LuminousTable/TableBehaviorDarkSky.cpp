#include "TableBehaviorDarkSky.h"


TableBehaviorDarkSky::TableBehaviorDarkSky()
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

  for(int i=0; i < STARS_COUNT; i++){
    starsPosition[i][0] = random(X_MAX);  
    starsPosition[i][1] = random(Y_MAX);
    starsPosition[i][2] = 128;
    starsPosition[i][3] = 128;
  }
}

void TableBehaviorDarkSky::readButtonBValue()
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

      for(int i=0; i < STARS_COUNT; i++){
        starsPosition[i][0] = random(X_MAX);  
        starsPosition[i][1] = random(Y_MAX);
        starsPosition[i][2] = 128;
        starsPosition[i][3] = 128;
      }

    }
  }
}

void TableBehaviorDarkSky::setDotColor(int red, int green, int blue)
{
  currentColor.r = red;
  currentColor.g = green;
  currentColor.b = blue;

}

void TableBehaviorDarkSky::doLoop()
{
  paintAll(CRGB::Black, false);

  for(int i=0; i < STARS_COUNT; i++){
    int x = starsPosition[i][0];
    int y = starsPosition[i][1];

    CRGB color;
    int speedShine = 6;

    if ( abs(starsPosition[i][2] - starsPosition[i][3]) < speedShine){
      int intensity = random(255);
      starsPosition[i][3] = intensity;

      if(starsPosition[i][2] < 25){
        starsPosition[i][0] = random(X_MAX);  
        starsPosition[i][1] = random(Y_MAX);
      }
    }

    if (starsPosition[i][2] > starsPosition[i][3]){

      starsPosition[i][2] = starsPosition[i][2] - speedShine;

      color.r = starsPosition[i][2];
      color.g = starsPosition[i][2];
      color.b = starsPosition[i][2];

    } 
    else  if (starsPosition[i][2] < starsPosition[i][3]){

      starsPosition[i][2] = starsPosition[i][2] + speedShine;

      color.r = starsPosition[i][2];
      color.g = starsPosition[i][2];
      color.b = starsPosition[i][2];
    }

    (*leds)[(*ledMatrix)[x][y]] = correctColor(x, color);     
  }

  FastLED.show();
  //delay(100);

  int i = 0;
  while(i < 5){
    delay(10);
    readPotentiometerValue();
    readButtonBValue();
    i++; 
  }
}

void TableBehaviorDarkSky::paintAll(CRGB color, boolean forceRefresh)
{

  for(int i=0; i < X_MAX; i++){
    for(int j=0; j < Y_MAX; j++){

      (*leds)[(*ledMatrix)[i][j]] = correctColor(i, color);

    }
  }

  if (forceRefresh){     
    FastLED.show(); 
  }
}

