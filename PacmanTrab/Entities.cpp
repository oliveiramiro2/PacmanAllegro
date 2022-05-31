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
