#include <iostream>
#include "Entities.h"


// controle de posicao para movimento
void Entities::setPosX(float value){
    Entities::posX = value;
}

void Entities::setPosY(float value){
    Entities::posY = value;
}

float Entities::getPosX(){
    return posX;
}

float Entities::getPosY(){
    return posY;
}

// controle para alterar a direcao do movimento
void Entities::setPositionMove(int value){
    Entities::positionMove = value;
}

int Entities::getPositionMove(){
    return Entities::positionMove;
}
