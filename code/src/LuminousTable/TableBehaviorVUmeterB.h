#ifndef _TABLE_BEHAVIOR_VUMETERB_H_
#define _TABLE_BEHAVIOR_VUMETERB_H_

#include "AbstractTableBehavior.h"
#include <QDebug>

class TableBehaviorVUmeterB :
public AbstractTableBehavior
{

public:
  TableBehaviorVUmeterB();
  virtual void doLoop();
  virtual void onClickButtonB();


  int currentIndex;
  int localSoundLevel;
};

#endif

