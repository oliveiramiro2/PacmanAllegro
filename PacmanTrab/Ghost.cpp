#include <iostream>
#include "Ghost.h"

#define PIXEL_GAME_SIZE 35
#define MAX_SIZE_TABLE 19

using namespace std;

Ghost::Ghost(int type){
    srand(time(NULL));

    switch(type){
    case 1:
        Ghost::setPosX(PIXEL_GAME_SIZE);
        Ghost::setPosY(PIXEL_GAME_SIZE);
        Ghost::setPositionMove(2);
        cout << "aleatorio: " << this->getPositionMove() << endl;
        break;
    case 2:
        Ghost::setPosX(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPosY(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPositionMove(1);
        cout << "aleatorio: " << this->getPositionMove() << endl;
        break;
    case 3:
        Ghost::setPosX(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPosY(PIXEL_GAME_SIZE);
        Ghost::setPositionMove(4);
        cout << "aleatorio: " << this->getPositionMove() << endl;
        break;
    case 4:
        Ghost::setPosX(PIXEL_GAME_SIZE);
        Ghost::setPosY(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPositionMove(4);
        cout << "aleatorio: " << this->getPositionMove() << endl;
        break;
    }
}

bool Ghost::checkMove(int table[19][19]){
    if(this->getPosX() % PIXEL_GAME_SIZE != 0 && this->getPosY() % PIXEL_GAME_SIZE != 0)
        return true;

    //if()
}

void Ghost::checkSide(int table[19][19], int x, int y){
    if(this->getPositionMove() == 1 || this->getPositionMove() == 3){
        if(table[y][x+1] != 0 || table[y][x-1] != 0){
            cout << "x: " << x << "Y: " << y << "aleatorio: " << (rand() % 4) + 1 << endl;
            this->setPositionMove((rand() % 4) + 1);
        }
    }else{
        if(table[y+1][x] != 0 || table[y-1][x] != 0){
                cout << "x: " << x << "Y: " << y << "aleatorio: " << (rand() % 4) + 1 << endl;
            this->setPositionMove((rand() % 4) + 1);
        }
    }
}
