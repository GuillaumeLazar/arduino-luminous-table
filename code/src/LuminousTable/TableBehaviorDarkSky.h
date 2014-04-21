#ifndef _TABLE_BEHAVIOR_DARK_SKY_H_
#define _TABLE_BEHAVIOR_DARK_SKY_H_

#include "AbstractTableBehavior.h"
#include "pitches.h"

#define BUTTON_B_PIN 3
#define SPEAKER_PIN 8

#define COLOR_COUNT 9
#define STARS_COUNT 40


class TableBehaviorDarkSky : 
public AbstractTableBehavior
{

public:
  TableBehaviorDarkSky();
  virtual void doLoop();

  void setDotColor(int red, int green, int blue);
  void readButtonBValue();
  void paintAll(CRGB color, boolean forceRefresh);

  int buttonBValue;
  int tableSubMode;

  CRGB currentColor;
  CRGB arrayColor[COLOR_COUNT];

  int arrayColorIndex;


  int starsPosition[STARS_COUNT][4];

};

#endif

