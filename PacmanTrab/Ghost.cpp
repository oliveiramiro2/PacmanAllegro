#include <iostream>
#include "Ghost.h"

#define PIXEL_GAME_SIZE 35
#define MAX_SIZE_TABLE 17

using namespace std;

Ghost::Ghost(int type){

    switch(type){
    case 1:
        Ghost::setPosX(PIXEL_GAME_SIZE);
        Ghost::setPosY(PIXEL_GAME_SIZE);
        Ghost::setPositionMove(2);
        break;
    case 2:
        Ghost::setPosX(PIXEL_GAME_SIZE*MAX_SIZE_TABLE-2);
        Ghost::setPosY(PIXEL_GAME_SIZE);
        Ghost::setPositionMove(2);
        break;
    case 3:
        Ghost::setPosX(PIXEL_GAME_SIZE);
        Ghost::setPosY(PIXEL_GAME_SIZE*MAX_SIZE_TABLE-2);
        Ghost::setPositionMove(2);
        break;
    case 4:
        Ghost::setPosX(PIXEL_GAME_SIZE*MAX_SIZE_TABLE-2);
        Ghost::setPosY(PIXEL_GAME_SIZE*MAX_SIZE_TABLE-2);
        Ghost::setPositionMove(2);
        break;
    default:
        Ghost::setPosX(PIXEL_GAME_SIZE*MAX_SIZE_TABLE-2);
        Ghost::setPosY(PIXEL_GAME_SIZE*MAX_SIZE_TABLE-2);
        Ghost::setPositionMove(2);
        break;

    }
}

Ghost::~Ghost(){
    al_destroy_bitmap(ghost);
}

