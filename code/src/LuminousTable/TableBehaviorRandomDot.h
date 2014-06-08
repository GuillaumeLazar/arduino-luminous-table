#ifndef _TABLE_BEHAVIOR_RANDOM_DOT_H_
#define _TABLE_BEHAVIOR_RANDOM_DOT_H_

#include "AbstractTableBehavior.h"

#define COLOR_COUNT 9

class TableBehaviorRandomDot : 
public AbstractTableBehavior
{

public:
  TableBehaviorRandomDot();
  virtual void doLoop();
  virtual void onClickButtonB();

  CRGB currentColor;
  CRGB arrayColor[COLOR_COUNT];

  int dotCounter;
};

#endif

