#include <stdarg.h>
#include <FastSPI_LED2.h>

#include "TableBehaviorSnake.h"
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
#define BEHAVIOR_COUNT 4
AbstractTableBehavior* arrayBehavior;
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
      //Serial.println(freeRam());
      delete arrayBehavior;
      //Serial.println(freeRam());
      
      
      switch(tableMode){
        case 0:
          arrayBehavior = new TableBehaviorSnake();
          break;
        case 1:
          arrayBehavior = new TableBehaviorRandomDot();
          break;
        case 2:
          arrayBehavior = new TableBehaviorUnicolor();
          break;
        case 3:
          arrayBehavior = new TableBehaviorDarkSky();
          break;
      }
      //Serial.println(freeRam());
      //Serial.println("");
      
      arrayBehavior->leds = &leds;
      arrayBehavior->ledMatrix = &ledMatrix;

      //arrayBehavior[tableMode]->paintAll(CRGB::Black, true);
      arrayBehavior->paintAll(CRGB::Black, true);

       
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
  
  arrayBehavior = new TableBehaviorSnake();
  arrayBehavior->leds = &leds;
  arrayBehavior->ledMatrix = &ledMatrix;
  arrayBehavior->doSetup();
}

// main loop
void loop()
{
  arrayBehavior->doLoop();
  readButtonAValue();
  
  //Serial.println(freeRam());
}

