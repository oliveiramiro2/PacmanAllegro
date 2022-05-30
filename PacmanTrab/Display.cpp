#include <iostream>
#include "Display.h"

#define DIMENSIONS_SCREEN_PACMAN 665
#define PIXEL_GAME_SIZE 35
#define MAX_SIZE_TABLE 19

using namespace std;

Display::Display(){
    if(!al_init()) {                                                                                    // verifica se a allegro iniciou normalmente
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o Allegro",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    Display::display = al_create_display(DIMENSIONS_SCREEN_PACMAN, DIMENSIONS_SCREEN_PACMAN);

    if(!display) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o display!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
   }
   al_clear_to_color(al_map_rgb(255,255,255));

}

void Display::drawWall(){
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


    al_draw_filled_rectangle((MAX_SIZE_TABLE-4)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-5)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-1)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-8)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-9)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-10)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-1)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-11)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-12)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-13)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle((MAX_SIZE_TABLE-14)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-1)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-15)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));

    al_draw_filled_rectangle(4*PIXEL_GAME_SIZE, 7*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, 8*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle(10*PIXEL_GAME_SIZE, 7*PIXEL_GAME_SIZE, 15*PIXEL_GAME_SIZE, 8*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));

    al_draw_filled_rectangle(4*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-8)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
    al_draw_filled_rectangle(10*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, 15*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-8)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));


    al_draw_filled_rectangle(4*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, 15*PIXEL_GAME_SIZE, 10*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));

}

void Display::drawSpritesFood(int sprite){

    al_init_image_addon();
    if(sprite == 1){
        Display::food = al_load_bitmap("smallFood.png");
    }
    if(sprite == 2){
        Display::food = al_load_bitmap("bigFood.png");
    }

    for(int i=1; i<MAX_SIZE_TABLE-1;i++){
        for(int j=1; j<MAX_SIZE_TABLE-1; j++){
            al_draw_bitmap(Display::food, i*PIXEL_GAME_SIZE, j*PIXEL_GAME_SIZE, ALLEGRO_FLIP_VERTICAL);
        }
    }

}
