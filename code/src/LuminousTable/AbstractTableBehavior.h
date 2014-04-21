#ifndef _ABSTRACT_TABLE_BEHAVIOR_H_
#define _ABSTRACT_TABLE_BEHAVIOR_H_

#include "Arduino.h"
#include "FastSPI_LED2.h"

#define NUM_LEDS 200
#define DATA_PIN 6
//#define CLOCK_PIN 8
#define X_MAX 20
#define Y_MAX 10

#define POT_PIN 0


class AbstractTableBehavior
{

public:
  void doBlack();
  void doSetup();
  virtual void doInit() { 
  };
  virtual void doLoop() = 0;

  CRGB (*leds)[NUM_LEDS];
  int (*ledMatrix)[X_MAX][Y_MAX];


protected:
  CRGB correctColor(int cols, CRGB color);
  void readPotentiometerValue();
  void initLedMatrix();

  int potValue;
  int newBrightness;

};

#endif


