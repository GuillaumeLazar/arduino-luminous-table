#ifndef _TABLE_BEHAVIOR_PIXELART_H_
#define _TABLE_BEHAVIOR_PIXELART_H_

#include "AbstractTableBehavior.h"

#define COLOR_COUNT 9

class TableBehaviorPixelart :
public AbstractTableBehavior
{

public:
  TableBehaviorPixelart();
  virtual void doLoop();
  virtual void onClickButtonB();

  CRGB currentColor;
  CRGB arrayColor[COLOR_COUNT];

  int arrayColorIndex;
};

#endif

