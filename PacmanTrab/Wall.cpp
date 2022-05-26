#include <iostream>
#include "Wall.h"

using namespace std;

void Wall::drawWall(){
    al_init_primitives_addon();

    al_draw_filled_rectangle(0,700,30,0, al_map_rgb(255,0,0)); // left
    al_draw_filled_rectangle(0,30,1200,0, al_map_rgb(255,0,0)); // top
    al_draw_filled_rectangle(1200,670,0,700, al_map_rgb(255,0,0)); // bottom
    al_draw_filled_rectangle(1170,0,1200,700, al_map_rgb(255,0,0)); // right
    al_flip_display();
}
