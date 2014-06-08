#ifndef _TABLE_BEHAVIOR_DARK_SKY_H_
#define _TABLE_BEHAVIOR_DARK_SKY_H_

#include "AbstractTableBehavior.h"

#define STARS_COUNT 20

class TableBehaviorDarkSky : 
public AbstractTableBehavior
{

public:
  TableBehaviorDarkSky();
  virtual void doLoop();
  virtual void onClickButtonB();

  int arrayColorIndex;
  int starsPosition[STARS_COUNT][4];

};

#endif

