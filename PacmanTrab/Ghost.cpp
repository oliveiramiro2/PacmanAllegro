#include <iostream>
#include "Ghost.h"

#define PIXEL_GAME_SIZE 35
#define MAX_SIZE_TABLE 19
#define SPEED 1

using namespace std;

Ghost::Ghost(int type){
    srand(time(NULL));

    switch(type){
    case 1:
        Ghost::setPosX(PIXEL_GAME_SIZE);
        Ghost::setPosY(PIXEL_GAME_SIZE);
        Ghost::setPositionMove(3);
        break;
    case 2:
        Ghost::setPosX(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPosY(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPositionMove(2);
        break;
    case 3:
        Ghost::setPosX(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPosY(PIXEL_GAME_SIZE);
        Ghost::setPositionMove(3);
        break;
    case 4:
        Ghost::setPosX(PIXEL_GAME_SIZE);
        Ghost::setPosY(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPositionMove(4);
        break;
    }
}

Ghost::~Ghost(){
    al_destroy_bitmap(this->ghost);
}


void Ghost::changeDirection(){
    this->setPositionMove((rand() % 4) + 1);
}

void Ghost::checkSide(int table[19][19], int x, int y){
    if(this->getPositionMove() == 1 || this->getPositionMove() == 3){
        if(table[y][x+1] != 0 || table[y][x-1] != 0){
            bool lock = true;

            while(lock){
                this->setPositionMove((rand() % 4) + 1);
                if(this->getPositionMove() == 1){
                    if(table[(this->getPosY() / PIXEL_GAME_SIZE)-1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34)
                        lock = false;
                }else if(this->getPositionMove() == 2){
                    if(table[this->getPosY() / PIXEL_GAME_SIZE][this->getPosX() / PIXEL_GAME_SIZE+1] != 0 && this->getPosX() > 34 && this->getPosY() > 34)
                        lock = false;
                }else if(this->getPositionMove() == 3){
                    if(table[this->getPosY() / PIXEL_GAME_SIZE+1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34)
                        lock = false;
                }else if(this->getPositionMove() == 4){
                    if(table[this->getPosY() / PIXEL_GAME_SIZE][(this->getPosX() / PIXEL_GAME_SIZE)-1] != 0 && this->getPosX() > 34 && this->getPosY() > 34)
                        lock = false;
                }
            }

        }
    }else if(this->getPositionMove() == 2 || this->getPositionMove() == 4){

        if(table[y+1][x] != 0 || table[y-1][x] != 0){
            bool lock = true;

            while(lock){
                this->setPositionMove((rand() % 4) + 1);
                if(this->getPositionMove() == 1){
                    if(table[(this->getPosY() / PIXEL_GAME_SIZE)-1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34)
                        lock = false;
                }else if(this->getPositionMove() == 2){
                    if(table[this->getPosY() / PIXEL_GAME_SIZE][this->getPosX() / PIXEL_GAME_SIZE+1] != 0 && this->getPosX() > 34 && this->getPosY() > 34)
                        lock = false;
                }else if(this->getPositionMove() == 3){
                    if(table[this->getPosY() / PIXEL_GAME_SIZE+1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34)
                        lock = false;
                }else if(this->getPositionMove() == 4){
                    if(table[this->getPosY() / PIXEL_GAME_SIZE][(this->getPosX() / PIXEL_GAME_SIZE)-1] != 0 && this->getPosX() > 34 && this->getPosY() > 34)
                        lock = false;
                }
            }
        }
    }
}
