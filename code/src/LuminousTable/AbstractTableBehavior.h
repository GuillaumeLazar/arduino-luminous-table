#ifndef _ABSTRACT_TABLE_BEHAVIOR_H_
#define _ABSTRACT_TABLE_BEHAVIOR_H_

#include "Arduino.h"
#include "FastSPI_LED2.h"
#include "pitches.h"

#define NUM_LEDS 200
#define DATA_PIN 6
//#define CLOCK_PIN 8
#define X_MAX 20
#define Y_MAX 10

#define POT_PIN 0
#define BUTTON_B_PIN 3
#define SPEAKER_PIN 8
#define MIC_ANALOG_PIN 1 //A1


class AbstractTableBehavior
{

public:

  virtual ~AbstractTableBehavior() { }

  void doSetup();
  void paintAll(CRGB color, boolean forceRefresh);  
  virtual void doInit() { };
  virtual void onClickButtonB() { }
  virtual void doLoop() = 0;
  
  CRGB (*leds)[NUM_LEDS];
  int (*ledMatrix)[X_MAX][Y_MAX];
  
  int buttonBValue;


protected:
  void readInputs();
  CRGB correctColor(int cols, CRGB color);
  void setCorrectColor(int x, int y, CRGB currentColor);
  void initLedMatrix();

  int potValue;
  int newBrightness;
  int mSoundLevel;

};

#endif


