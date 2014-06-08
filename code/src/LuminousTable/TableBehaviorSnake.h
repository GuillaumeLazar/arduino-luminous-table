#ifndef _TABLE_BEHAVIOR_SNAKE_H_
#define _TABLE_BEHAVIOR_SNAKE_H_

#include "AbstractTableBehavior.h"

#define  SNAKEMAXSIZE 30
  


class TableBehaviorSnake : 
public AbstractTableBehavior
{

    struct SnakeUnit{
        int x;
        int y;

        SnakeUnit(){
            set(x, y);
        }

        SnakeUnit(int x, int y){
            set(x, y);
        }

        void set(int x, int y){
            this->x = x;
            this->y = y;
        }

    };

public:
  TableBehaviorSnake();
  virtual ~TableBehaviorSnake();
  virtual void doLoop();
  virtual void onClickButtonB();

protected:
  int isPositionEmpty(int newX, int newY);
  void growUp();

  int mSnakeSize;
  CRGB mSnakeColor;
  SnakeUnit* mSnake[SNAKEMAXSIZE];
  int mDirection;
};

#endif

