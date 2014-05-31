#ifndef SIMULATORBEHAVIORSNAKE_H
#define SIMULATORBEHAVIORSNAKE_H

#include "abstractsimulatorbehavior.h"



class SimulatorBehaviorSnake : public AbstractSimulatorBehavior
{
    Q_OBJECT

    struct SnakeUnit{
        int x;
        int y;

        SnakeUnit(){
            this->x = 0;
            this->y = 0;
        }

        SnakeUnit(int x, int y){
            this->x = x;
            this->y = y;
        }

    };

public:
    explicit SimulatorBehaviorSnake(QWidget *parent = 0);

    virtual void onClickButtonB();

protected:
    virtual void init();

    int isPositionEmpty(int newX, int newY);
    void growUp();

    #define  SNAKEMAXSIZE 100

    int mSnakeSize;
    CRGB mSnakeColor;
    SnakeUnit* mSnake[SNAKEMAXSIZE];
    int mDirection;

protected slots:
    virtual void loop();

private:

};

#endif // SIMULATORBEHAVIORSNAKE_H
