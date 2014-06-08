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
    explicit SimulatorBehaviorSnake(QWidget *parent = 0);
    ~SimulatorBehaviorSnake();

    virtual void onClickButtonB();

protected:
    virtual void init();

    int isPositionEmpty(int newX, int newY);
    void growUp();

    #define  SNAKEMAXSIZE 10

    int mSnakeSize;
    CRGB mSnakeColor;
    SnakeUnit* mSnake[SNAKEMAXSIZE];
    int mDirection;

protected slots:
    virtual void loop();

private:

};

#endif // SIMULATORBEHAVIORSNAKE_H
