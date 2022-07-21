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
        Ghost::setTypeStalker(type);
        break;
    case 2:
        Ghost::setPosX(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPosY(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPositionMove(2);
        Ghost::setTypeStalker(type);
        break;
    case 3:
        Ghost::setPosX(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPosY(PIXEL_GAME_SIZE);
        Ghost::setPositionMove(3);
        Ghost::setTypeStalker(type);
        break;
    case 4:
        Ghost::setPosX(PIXEL_GAME_SIZE);
        Ghost::setPosY(PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-2));
        Ghost::setPositionMove(4);
        Ghost::setTypeStalker(type);
        break;
    }
}

Ghost::~Ghost(){
    al_destroy_bitmap(this->ghost);
}


void Ghost::changeDirection(int table[19][19], int x, int y, int pacmanX, int pacmanY){
    if(this->getTypeStalker() % 2 == 0){
        this->setPositionMove((rand() % 4) + 1);
        return;
    }

    // cout << "ValorX: \n" << pacmanX << "    -   ValorY: " << pacmanY << endl;
    int biggerX, biggerY;
    bool xIsBigger, yIsBigger;

    if(x > pacmanX){
        biggerX = x - pacmanX;
        xIsBigger = true;
    }else{
        biggerX = pacmanX - x;
        xIsBigger = false;
    }if(y > pacmanX){
        biggerY = y - pacmanX;
        yIsBigger = true;
    }else{
        biggerY = pacmanX - y;
        yIsBigger = false;
    }

    if(biggerX == 0){
        if(y < pacmanY){
            if(table[(this->getPosY() / PIXEL_GAME_SIZE)+1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                this->setPositionMove(3);
                return;
            }
        }else{
            if(table[(this->getPosY() / PIXEL_GAME_SIZE)-1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
               this->setPositionMove(1);
                return;
            }
        }
    }

    if(biggerY == 0){
        if(x < pacmanX){
            if(table[this->getPosY() / PIXEL_GAME_SIZE][(this->getPosX() / PIXEL_GAME_SIZE)+1] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                this->setPositionMove(2);
                return;
            }
        }else{
            if(table[this->getPosY() / PIXEL_GAME_SIZE][this->getPosX() / PIXEL_GAME_SIZE-1] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                this->setPositionMove(4);
                return;
            }
        }
    }

    if(biggerX < biggerY){
        if(xIsBigger){
            if(table[this->getPosY() / PIXEL_GAME_SIZE][this->getPosX() / PIXEL_GAME_SIZE-1] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                this->setPositionMove(4);
                return;
            }else if(yIsBigger){
                if(table[(this->getPosY() / PIXEL_GAME_SIZE)-1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                   this->setPositionMove(1);
                    return;
                }
            }else if(!yIsBigger){
                if(table[(this->getPosY() / PIXEL_GAME_SIZE)+1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                    this->setPositionMove(3);
                    return;
                }
            }
        }else if(!xIsBigger){
            if(table[this->getPosY() / PIXEL_GAME_SIZE][(this->getPosX() / PIXEL_GAME_SIZE)+1] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                this->setPositionMove(2);
                return;
            }else if(yIsBigger){
                if(table[(this->getPosY() / PIXEL_GAME_SIZE)-1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                   this->setPositionMove(1);
                    return;
                }
            }else if(!yIsBigger){
                if(table[(this->getPosY() / PIXEL_GAME_SIZE)+1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                    this->setPositionMove(3);
                    return;
                }
            }
        }
    }else{
        if(yIsBigger){
            if(table[(this->getPosY() / PIXEL_GAME_SIZE)-1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                this->setPositionMove(1);
                return;
            }else if(xIsBigger){
                if(table[this->getPosY() / PIXEL_GAME_SIZE][this->getPosX() / PIXEL_GAME_SIZE-1] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                    this->setPositionMove(4);
                    return;
                }
            }else if(!xIsBigger){
                if(table[this->getPosY() / PIXEL_GAME_SIZE][(this->getPosX() / PIXEL_GAME_SIZE)+1] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                    this->setPositionMove(2);
                    return;
                }
            }
        }else if(!yIsBigger){
            if(table[(this->getPosY() / PIXEL_GAME_SIZE)+1][this->getPosX() / PIXEL_GAME_SIZE] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                this->setPositionMove(3);
                return;
            }else if(xIsBigger){
                if(table[this->getPosY() / PIXEL_GAME_SIZE][this->getPosX() / PIXEL_GAME_SIZE-1] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                    this->setPositionMove(4);
                    return;
                }
            }else if(!xIsBigger){
                if(table[this->getPosY() / PIXEL_GAME_SIZE][(this->getPosX() / PIXEL_GAME_SIZE)+1] != 0 && this->getPosX() > 34 && this->getPosY() > 34){
                    this->setPositionMove(2);
                    return;
                }
            }
        }
    }

    this->setPositionMove((rand() % 4) + 1);
    return;
}

void Ghost::checkSide(int table[19][19], int x, int y, int pacmanX, int pacmanY){
    if(this->getPositionMove() == 1 || this->getPositionMove() == 3){
        if(table[y][x+1] != 0 || table[y][x-1] != 0){
            bool lock = true;

            while(lock){
                this->changeDirection(table, x, y, pacmanX, pacmanY);
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
                this->changeDirection(table, x, y, pacmanX, pacmanY);
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

void Ghost::setTypeStalker(int value){
    Ghost::typeStalker = value;
}

int Ghost::getTypeStalker(){
    return Ghost::typeStalker;
}
