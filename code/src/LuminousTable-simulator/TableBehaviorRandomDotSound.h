#ifndef _TABLE_BEHAVIOR_RANDOM_DOT_SOUND_H_
#define _TABLE_BEHAVIOR_RANDOM_DOT_SOUND_H_

#include "AbstractTableBehavior.h"
#include <QDebug>

class TableBehaviorRandomDotSound :
public AbstractTableBehavior
{

public:
  TableBehaviorRandomDotSound();
  virtual void doLoop();
  virtual void onClickButtonB();


  int currentIndex;
  int localSoundLevel;
};

#endif

