#ifndef _TABLE_BEHAVIOR_UNICOLOR_H_
#define _TABLE_BEHAVIOR_UNICOLOR_H_

#include "AbstractTableBehavior.h"
#include "pitches.h"

//#include <TableLed.h>

#define BUTTON_B_PIN 3
#define SPEAKER_PIN 8

#define COLOR_COUNT 9

class TableBehaviorUnicolor : 
public AbstractTableBehavior
{

public:
  TableBehaviorUnicolor();
  virtual void doLoop();

  void setDotColor(int red, int green, int blue);
  void readButtonBValue();
  void paintAll(CRGB color);

  int buttonBValue;
  int tableSubMode;

  CRGB currentColor;
  CRGB arrayColor[COLOR_COUNT];

  int arrayColorIndex;
};

#endif

