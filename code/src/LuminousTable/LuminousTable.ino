#include <stdarg.h>
#include <FastSPI_LED2.h>

#include "TableBehaviorRandomDot.h"
#include "TableBehaviorUnicolor.h"
#include "TableBehaviorDarkSky.h"

// pin defines
#define BUTTON_A_PIN 4
#define SPEAKER_PIN 8
int buttonAValue = 0;

// leds control
CRGB leds[NUM_LEDS];
int ledMatrix[X_MAX][Y_MAX];

// 
#define BEHAVIOR_COUNT 3
AbstractTableBehavior* arrayBehavior[BEHAVIOR_COUNT];
TableBehaviorRandomDot tableBehaviorRandomDot;
TableBehaviorUnicolor tableBehaviorUnicolor;
TableBehaviorDarkSky tableBehaviorDarkSky;
int tableMode = 0;

// TODO: put it into Utils
int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

// TODO: put it into Utils
void serialPrintf(char *fmt, ... )
{
  char tmp[128]; // resulting string limited to 128 chars
  va_list args;
  va_start (args, fmt );
  vsnprintf(tmp, 128, fmt, args);
  va_end (args);
  Serial.print(tmp);
}

// change the current mode and apply the new beahavior 
void readButtonAValue()
{
  int val = digitalRead(BUTTON_A_PIN);
  
  if (val != buttonAValue){
    buttonAValue = val;
    //serialPrintf("button A = %d\n", buttonAValue);

    if (buttonAValue == HIGH){
      int noteDuration = 200;
      tone(SPEAKER_PIN, NOTE_C5, noteDuration);
      delay(noteDuration);
      noTone(SPEAKER_PIN);
      
    }else{
      
      
      tableMode ++;
      tableMode = tableMode % BEHAVIOR_COUNT;

      arrayBehavior[tableMode]->paintAll(CRGB::Black, true);
      //arrayBehavior[tableMode]->doBlack();
       
      //serialPrintf("tableMode = %d\n", tableMode);
    }
  }
}

// initialization
void setup()
{
  delay(2000);

  Serial.begin(9600);
  randomSeed(analogRead(2));

  //global init
  arrayBehavior[0] = &tableBehaviorRandomDot;
  arrayBehavior[1] = &tableBehaviorUnicolor;
  arrayBehavior[2] = &tableBehaviorDarkSky;
  
  //Behavior # 0
  arrayBehavior[0]->leds = &leds;
  arrayBehavior[0]->ledMatrix = &ledMatrix;
  arrayBehavior[0]->doSetup();
  
  //Behavior # 1
  arrayBehavior[1]->leds = &leds;
  arrayBehavior[1]->ledMatrix = &ledMatrix;
  
  //Behavior # 2
  arrayBehavior[2]->leds = &leds;
  arrayBehavior[2]->ledMatrix = &ledMatrix;

}

// main loop
void loop()
{
  arrayBehavior[tableMode]->doLoop();
  readButtonAValue();
  
  //Serial.println(freeRam());
}

