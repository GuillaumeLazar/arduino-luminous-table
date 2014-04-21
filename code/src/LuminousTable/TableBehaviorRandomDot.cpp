#include "TableBehaviorRandomDot.h"


TableBehaviorRandomDot::TableBehaviorRandomDot()
{
  randomSeed(analogRead(5));

  buttonBValue = 0;
  tableSubMode = 0;
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

void TableBehaviorRandomDot::readButtonBValue()
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

      currentColor = arrayColor[random(COLOR_COUNT)];

      Serial.println(dotCounter);
      dotCounter = 0;
    }
  }
}


void TableBehaviorRandomDot::setDotColor(int red, int green, int blue)
{
  currentColor.r = red;
  currentColor.g = green;
  currentColor.b = blue;
}

void TableBehaviorRandomDot::doLoop()
{

  int x = random(20);
  int y = random(10);

  (*leds)[(*ledMatrix)[x][y]] = correctColor(x, currentColor);
  dotCounter ++;

  FastLED.show();

  int i = 0;
  while(i < 5){
    delay(10);
    readPotentiometerValue();
    readButtonBValue();
    i++; 
  }


  //check auto change mode
  if (dotCounter > 250){
    //Serial.println(dotCounter);
    currentColor = arrayColor[random(COLOR_COUNT)];
    dotCounter = 0;
  }
}

