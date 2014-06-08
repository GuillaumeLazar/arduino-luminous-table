#include "simulatorbehaviorsnake.h"

SimulatorBehaviorSnake::SimulatorBehaviorSnake(QWidget *parent) :
    AbstractSimulatorBehavior(parent)
{
    this->init();
    this->startLoop();
}

SimulatorBehaviorSnake::~SimulatorBehaviorSnake()
{
    for (int i = 0; i < SNAKEMAXSIZE; ++i) {
        delete mSnake[i];
    }
}

void SimulatorBehaviorSnake::init()
{
    mSnakeColor = CRGB::Green;
    for (int i = 0; i < SNAKEMAXSIZE; ++i) {
        mSnake[i] = new SnakeUnit();
    }

    mSnakeSize = 3;
    mSnake[0]->set(9, 4);
    mSnake[1]->set(9, 3);
    mSnake[2]->set(9, 2);

    mDirection = 0;
}

void SimulatorBehaviorSnake::onClickButtonB()
{
    //mDirection = random(4);
    growUp();
}

void SimulatorBehaviorSnake::growUp()
{
    if (mSnakeSize < SNAKEMAXSIZE){
        mSnake[mSnakeSize]->set(mSnake[mSnakeSize - 1]->x, mSnake[mSnakeSize - 1]->y);
        mSnakeSize++;
    }
}

int SimulatorBehaviorSnake::isPositionEmpty(int x, int y)
{
    // Check gamefield
    if (x < 0){return 0;}
    if (y < 0){return 0;}
    if (x >= 20){return 0;}
    if (y >= 10){return 0;}

    // Check each Snake units
    for (int i = 0; i < mSnakeSize; ++i) {
        if (mSnake[i]->x == x && mSnake[i]->y == y){
            return 0;
        }
    }

    return 1;
}

void SimulatorBehaviorSnake::loop()
{
    paintAll(CRGB::Black, false);

    int newPosX = -1;
    int newPosY = -1;

    int randomTryCount = 0;

    while(newPosX == -1 && randomTryCount < 500){


        switch (mDirection) {
        case 0:
            if(isPositionEmpty(mSnake[0]->x - 1, mSnake[0]->y) == 1){
                newPosX = mSnake[0]->x - 1;
                newPosY = mSnake[0]->y;
            }
            break;

        case 1:
            if(isPositionEmpty(mSnake[0]->x + 1, mSnake[0]->y) == 1){
                newPosX = mSnake[0]->x + 1;
                newPosY = mSnake[0]->y;
            }
            break;
        case 2:
            if(isPositionEmpty(mSnake[0]->x, mSnake[0]->y - 1) == 1){
                newPosX = mSnake[0]->x;
                newPosY = mSnake[0]->y - 1;
            }
            break;
        case 3:
            if(isPositionEmpty(mSnake[0]->x, mSnake[0]->y + 1) == 1){
                newPosX = mSnake[0]->x;
                newPosY = mSnake[0]->y + 1;
            }
            break;
        default:
            break;
        }

        if (newPosX == -1){
            mDirection = random(4);
            randomTryCount++;
        }
    }

    // Gameover ?
    if (newPosX == -1 || newPosY == -1){

        delay(1000);
        mSnakeSize = 3;
        mSnake[0]->set(9, 4);
        mSnake[1]->set(9, 3);
        mSnake[2]->set(9, 2);

    }else{
        // move the snake
        SnakeUnit previousValues;
        SnakeUnit newValues;
        for (int i = 0; i < mSnakeSize; ++i) {

            int tmpX = mSnake[i]->x;
            int tmpY = mSnake[i]->y;


            // if 'head' else 'body'
            if (i == 0){
                newValues.x = newPosX;
                newValues.y = newPosY;

            }else{
                newValues.x = previousValues.x;
                newValues.y = previousValues.y;
            }

            // Apply new values
            mSnake[i]->x = newValues.x;
            mSnake[i]->y = newValues.y;

            // Store old values
            previousValues.x = tmpX;
            previousValues.y = tmpY;

            setCorrectColor(mSnake[i]->x,  mSnake[i]->y, mSnakeColor);
        }
    }

    // Sometimes change the direction
    if (random(100) > 80){
        mDirection = random(4);
    }

    // Sometimes growup
    if (random(100) > 95){
        growUp();
    }

    FastLED.show();

    delay(100);

    // read any changes on Potentiometer and Button B
    readInputs();
}
