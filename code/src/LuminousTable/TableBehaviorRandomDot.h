#ifndef _TABLE_BEHAVIOR_RANDOM_DOT_H_
#define _TABLE_BEHAVIOR_RANDOM_DOT_H_

#include "AbstractTableBehavior.h"
#include "pitches.h"

#define BUTTON_B_PIN 3
#define SPEAKER_PIN 8

#define COLOR_COUNT 9

class TableBehaviorRandomDot : 
public AbstractTableBehavior
{

public:
  TableBehaviorRandomDot();
  virtual void doLoop();

  void setDotColor(int red, int green, int blue);
  void readButtonBValue();

  int buttonBValue;
  int tableSubMode;

  CRGB currentColor;
  CRGB arrayColor[COLOR_COUNT];

  int dotCounter;
};

#endif

