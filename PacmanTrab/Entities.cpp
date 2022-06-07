#include <iostream>
#include "Entities.h"


// controle de posicao para movimento
void Entities::setPosX(int value){
    Entities::posX = value;
}

void Entities::setPosY(int value){
    Entities::posY = value;
}

int Entities::getPosX(){
    return posX;
}

int Entities::getPosY(){
    return posY;
}

// controle para alterar a direcao do movimento
void Entities::setPositionMove(int value){
    Entities::positionMove = value;
}

int Entities::getPositionMove(){
    return Entities::positionMove;
}
