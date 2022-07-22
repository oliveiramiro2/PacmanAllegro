#include <iostream>
#include "Ghost.h"

#define PIXEL_GAME_SIZE 35
#define MAX_SIZE_TABLE 19
#define SPEED 1

using namespace std;

Ghost::Ghost(int type){
    srand(time(NULL));                                                                      // plantando uma semente para gerar numeros aleatorios

    switch(type){                                                                           // escolhendo o tipo de fantasma e colocando na posicao inicial
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
    al_destroy_bitmap(this->ghost);                                                                         // desalocando ponteiro do bitman dos fantasmas
}


void Ghost::changeDirection(int table[19][19], int x, int y, int pacmanX, int pacmanY){                     // mudando a direcao do fantasma
    if(this->getTypeStalker() % 2 == 0){                                                                    // fantasmas 2 e 4 serao aleatorios
        this->setPositionMove((rand() % 4) + 1);
        return;
    }

    if((y == pacmanY) && (x > pacmanX) && (table[y][x-1] != 0)){                                            // checa se esta no msm sqm no y e se é possivel diminiur a distancia do x
        this->setPositionMove(4);
        return;
    }

    if((y == pacmanY) && (x < pacmanX) && (table[y][x+1] != 0)){                                            // checa se esta no msm sqm no y e se é possivel diminiur a distancia do x
        this->setPositionMove(2);
        return;
    }

    if((x == pacmanX) && (y > pacmanY) && (table[y-1][x] != 0)){                                            // checa se esta no msm sqm no x e se é possivel diminiur a distancia do y
        this->setPositionMove(1);
        return;
    }

    if((x == pacmanX) && (y < pacmanY) && (table[y+1][x] != 0)){                                            // checa se esta no msm sqm no x e se é possivel diminiur a distancia do y
        this->setPositionMove(3);
        return;
    }




    if((x > pacmanX) && (table[y][x-1] != 0)){                                                              // checa se o fantasma esta numa posicao maior no eixo x se e possivel diminuir
        this->setPositionMove(4);
        return;
    }

    if((x < pacmanX) && (table[y][x+1] != 0)){                                                              // checa se o fantasma esta numa posicao menor no eixo x se e possivel aumentar
        this->setPositionMove(2);
        return;
    }

    if((y > pacmanY) && (table[y-1][x] != 0)){                                                              // checa se o fantasma esta numa posicao maior no eixo y se e possivel diminuir
        this->setPositionMove(1);
        return;
    }

    if((y < pacmanY) && (table[y+1][x] != 0)){                                                              // checa se o fantasma esta numa posicao menor no eixo y se e possivel aumentar
        this->setPositionMove(3);
        return;
    }

    this->setPositionMove((rand() % 4) + 1);                                                                // caso tudo der errado a posicao sera aleatoria
    return;
}

void Ghost::checkSide(int table[19][19], int x, int y, int pacmanX, int pacmanY){                           // checa os lados em uma encruzilhada
    if(this->getPositionMove() == 1 || this->getPositionMove() == 3){                                       // movendo no eixo y?
        if(table[y][x+1] != 0 || table[y][x-1] != 0){                                                       // tem posicoes livres no eixo x?
            bool lock = true;

            while(lock){                                                                                    // laco p/ setar valor ate sair um valido
                this->changeDirection(table, x, y, pacmanX, pacmanY);                                       // setando a direcao e verificando a disponibilidade
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
    }else if(this->getPositionMove() == 2 || this->getPositionMove() == 4){                                 // movendo no eixo x?

        if(table[y+1][x] != 0 || table[y-1][x] != 0){                                                       // tem espaco disponiveis no eixo y?
            bool lock = true;

            while(lock){                                                                                    // laco p/ setar valor ate sair um valido
                this->changeDirection(table, x, y, pacmanX, pacmanY);                                       // setando a direcao e verificando a disponibilidade
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
