#ifndef _TABLE_BEHAVIOR_VUMETER_H_
#define _TABLE_BEHAVIOR_VUMETER_H_

#include "AbstractTableBehavior.h"

#define COLOR_COUNT 9

class TableBehaviorVUmeter :
public AbstractTableBehavior
{

public:
  TableBehaviorVUmeter();
  virtual void doLoop();
  virtual void onClickButtonB();


  int currentSoundLevel;
  int currentTopBarLevel;
  int currentTopBarLevelCpt;
};

#endif

