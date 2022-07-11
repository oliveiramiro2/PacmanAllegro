#include <iostream>
#include "Ghost.h"

using namespace std;

Ghost::Ghost(int type){
    al_init_image_addon();

    Ghost::setPosX(35);
    Ghost::setPosY(35);
    Ghost::setPositionMove(2);
}

Ghost::~Ghost(){
    al_destroy_bitmap(ghost);
}

void Ghost::drawGhost(){
    al_draw_bitmap(ghost, 70, 70, ALLEGRO_FLIP_HORIZONTAL);
}

