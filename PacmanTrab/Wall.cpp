#include <iostream>
#include "Wall.h"

#define PIXEL_GAME_SIZE 35
#define MAX_SIZE_TABLE 19
#define DIMENSIONS_SCREEN_PACMAN 665

using namespace std;

void Wall::drawWall(){
    al_init_primitives_addon();

    al_draw_filled_rectangle(0,DIMENSIONS_SCREEN_PACMAN,PIXEL_GAME_SIZE,0, al_map_rgb(255,0,0)); // left
    al_draw_filled_rectangle(0,PIXEL_GAME_SIZE,DIMENSIONS_SCREEN_PACMAN,0, al_map_rgb(255,0,0)); // top
    al_draw_filled_rectangle(DIMENSIONS_SCREEN_PACMAN,DIMENSIONS_SCREEN_PACMAN-PIXEL_GAME_SIZE,0,DIMENSIONS_SCREEN_PACMAN, al_map_rgb(255,0,0)); // bottom
    al_draw_filled_rectangle(DIMENSIONS_SCREEN_PACMAN-PIXEL_GAME_SIZE,0,DIMENSIONS_SCREEN_PACMAN,DIMENSIONS_SCREEN_PACMAN, al_map_rgb(255,0,0)); // right

    al_draw_filled_rectangle(2*PIXEL_GAME_SIZE, 2*PIXEL_GAME_SIZE, 3*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, 2*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-3)*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));

    al_draw_filled_rectangle(2*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, 3*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-9)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-3)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-9)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));


    al_draw_filled_rectangle(4*PIXEL_GAME_SIZE, 2*PIXEL_GAME_SIZE, 5*PIXEL_GAME_SIZE, 6*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle(6*PIXEL_GAME_SIZE, 2*PIXEL_GAME_SIZE, 7*PIXEL_GAME_SIZE, 6*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle(8*PIXEL_GAME_SIZE, 2*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, 6*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle(10*PIXEL_GAME_SIZE, 2*PIXEL_GAME_SIZE, 11*PIXEL_GAME_SIZE, 6*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle(12*PIXEL_GAME_SIZE, 2*PIXEL_GAME_SIZE, 13*PIXEL_GAME_SIZE, 6*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle(14*PIXEL_GAME_SIZE, 2*PIXEL_GAME_SIZE, 15*PIXEL_GAME_SIZE, 6*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));


    al_draw_filled_rectangle((MAX_SIZE_TABLE-4)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-5)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-8)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-9)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-10)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-11)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-12)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-13)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-14)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-15)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));

    al_draw_filled_rectangle(4*PIXEL_GAME_SIZE, 7*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, 8*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle(10*PIXEL_GAME_SIZE, 7*PIXEL_GAME_SIZE, 15*PIXEL_GAME_SIZE, 8*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));

    al_draw_filled_rectangle(4*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-8)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle(10*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, 15*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-8)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));


    al_draw_filled_rectangle(4*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, 15*PIXEL_GAME_SIZE, 10*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));

//    al_draw_line(100,100,100,300, al_map_rgb(255,0,0), 40);
//    al_draw_line(100,350,100,620, al_map_rgb(255,0,0), 40);

//   al_draw_line(200,100,200,170, al_map_rgb(255,0,0), 40);
//    al_draw_line(350,100,350,170, al_map_rgb(255,0,0), 40);
//    al_draw_line(500,100,500,170, al_map_rgb(255,0,0), 40);
//    al_draw_line(650,100,650,170, al_map_rgb(255,0,0), 40);
//    al_draw_line(800,100,800,170, al_map_rgb(255,0,0), 40);
//    al_draw_line(950,100,950,170, al_map_rgb(255,0,0), 40);
//    al_draw_line(180,250,970,250, al_map_rgb(255,0,0), 40);

//    al_draw_line(180,320,970,320, al_map_rgb(255,0,0), 40);
//
//    al_draw_line(1050,100,1050,300, al_map_rgb(255,0,0), 40);
//    al_draw_line(1050,350,1050,620, al_map_rgb(255,0,0), 40);
/*
    for(int i=0; i<=MAX_SIZE_TABLE; i++){
        al_draw_filled_rectangle(0*PIXEL_GAME_SIZE,0*PIXEL_GAME_SIZE,1*PIXEL_GAME_SIZE,i*PIXEL_GAME_SIZE, al_map_rgb(0,0,255));
        al_draw_filled_rectangle((PIXEL_GAME_SIZE-1)*PIXEL_GAME_SIZE,PIXEL_GAME_SIZE*PIXEL_GAME_SIZE,i*PIXEL_GAME_SIZE,1*PIXEL_GAME_SIZE, al_map_rgb(0,0,255));
    }
/*
    for(int i=MAX_SIZE_TABLE; i<0; i++){
        al_draw_filled_rectangle(0*PIXEL_GAME_SIZE,0*PIXEL_GAME_SIZE,1*PIXEL_GAME_SIZE,i*PIXEL_GAME_SIZE, al_map_rgb(0,0,255));
        al_draw_filled_rectangle(0*PIXEL_GAME_SIZE,0*PIXEL_GAME_SIZE,i*PIXEL_GAME_SIZE,1*PIXEL_GAME_SIZE, al_map_rgb(0,0,255));
    }
 */

    al_flip_display();
}
