#ifndef _TABLE_BEHAVIOR_UNICOLOR_H_
#define _TABLE_BEHAVIOR_UNICOLOR_H_

#include "AbstractTableBehavior.h"

#define COLOR_COUNT 9

class TableBehaviorUnicolor : 
public AbstractTableBehavior
{

public:
  TableBehaviorUnicolor();
  virtual void doLoop();
  virtual void onClickButtonB();

  CRGB currentColor;
  CRGB arrayColor[COLOR_COUNT];

  int arrayColorIndex;
};

#endif

