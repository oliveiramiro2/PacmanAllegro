#include <iostream>
#include <string>
#include "Display.h"

#define DIMENSIONS_SCREEN_PACMAN 665
#define PIXEL_GAME_SIZE 35
#define MAX_SIZE_TABLE 19

using namespace std;

Display::Display(){
    // iniciando e verificando a tela
    if(!al_init()) {                                                                                    // verifica se a allegro iniciou normalmente
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o Allegro",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    Display::display = al_create_display(DIMENSIONS_SCREEN_PACMAN, DIMENSIONS_SCREEN_PACMAN);

    if(!display) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o display!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    // iniciando sprites e setando a cor branca na tela
    al_init_image_addon();
    al_clear_to_color(al_map_rgb(255,255,255));
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();

    // iniciando texto
    Display::fontDefault = al_load_font("./assets/Montserrat.ttf", 20, 0);

    // setando a posicao inicial do pacman no centro da tela e setando seu movimento a direita
    Entities::setPosX(9*PIXEL_GAME_SIZE);
    Entities::setPosY(10*PIXEL_GAME_SIZE);
    Entities::setPositionMove(2);
}

Display::~Display(){
    al_destroy_font(fontDefault);
    free(ghost1);
}

void Display::drawWall(){
    // wall around
    for(int i=1; i<MAX_SIZE_TABLE; i++){
        al_draw_filled_rectangle(0, ((MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE)-1, PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-i-1)*(PIXEL_GAME_SIZE), al_map_rgb(255,0,0)); // left
        al_draw_filled_rectangle((MAX_SIZE_TABLE-i+1)*(PIXEL_GAME_SIZE),PIXEL_GAME_SIZE,((MAX_SIZE_TABLE-i+2)*PIXEL_GAME_SIZE)-1, 0, al_map_rgb(255,0,0)); // top
        al_draw_filled_rectangle(((MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE)-1,DIMENSIONS_SCREEN_PACMAN-PIXEL_GAME_SIZE,(MAX_SIZE_TABLE-i-1)*(PIXEL_GAME_SIZE),DIMENSIONS_SCREEN_PACMAN, al_map_rgb(255,0,0)); // bottom
        al_draw_filled_rectangle(DIMENSIONS_SCREEN_PACMAN-PIXEL_GAME_SIZE,(i * PIXEL_GAME_SIZE)+1, DIMENSIONS_SCREEN_PACMAN,((i+1)*PIXEL_GAME_SIZE)-1, al_map_rgb(255,0,0)); // right
    }
    al_draw_filled_rectangle(36,PIXEL_GAME_SIZE,69, 0, al_map_rgb(255,0,0));


    // Wall inside
    for(int i=1; i<MAX_SIZE_TABLE; i++){
        // upside horizontal
        if(i >= 2 && i <= 5){
            al_draw_filled_rectangle(4*PIXEL_GAME_SIZE, i*PIXEL_GAME_SIZE, 5*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), al_map_rgb(255,0,0));
            al_draw_filled_rectangle(6*PIXEL_GAME_SIZE, i*PIXEL_GAME_SIZE, 7*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), al_map_rgb(255,0,0));
            al_draw_filled_rectangle(8*PIXEL_GAME_SIZE, i*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), al_map_rgb(255,0,0));
            al_draw_filled_rectangle(10*PIXEL_GAME_SIZE, i*PIXEL_GAME_SIZE, 11*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), al_map_rgb(255,0,0));
            al_draw_filled_rectangle(12*PIXEL_GAME_SIZE, i*PIXEL_GAME_SIZE, 13*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), al_map_rgb(255,0,0));
            al_draw_filled_rectangle(14*PIXEL_GAME_SIZE, i*PIXEL_GAME_SIZE, 15*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), al_map_rgb(255,0,0));
        }

        // downside horizontal
        if(i >= 2 && i <= 6){
                if(i <= 5){
                    al_draw_filled_rectangle((MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(i+1))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
                    al_draw_filled_rectangle((MAX_SIZE_TABLE-10)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-11)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(i+1))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
                    al_draw_filled_rectangle((MAX_SIZE_TABLE-14)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-15)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(i+1))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
                }
                if(i >= 2 && i <= 7){
                    al_draw_filled_rectangle((MAX_SIZE_TABLE-4)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-5)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(i+1))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
                    al_draw_filled_rectangle((MAX_SIZE_TABLE-8)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-9)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(i+1))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
                    al_draw_filled_rectangle((MAX_SIZE_TABLE-12)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-13)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(i+1))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
                }
                al_draw_filled_rectangle((MAX_SIZE_TABLE-6)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-1)*PIXEL_GAME_SIZE)-1), (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(2))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
                    al_draw_filled_rectangle((MAX_SIZE_TABLE-10)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-1)*PIXEL_GAME_SIZE)-1), (MAX_SIZE_TABLE-11)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(2))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
                    al_draw_filled_rectangle((MAX_SIZE_TABLE-14)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-1)*PIXEL_GAME_SIZE)-1), (MAX_SIZE_TABLE-15)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(2))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
        }

        // bigger column horizontal upside and downside
        if(i >= 2 && i <= 8 ){
            al_draw_filled_rectangle(2*PIXEL_GAME_SIZE, i*PIXEL_GAME_SIZE, 3*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), al_map_rgb(255,0,0));
            al_draw_filled_rectangle((MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, i*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-3)*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), al_map_rgb(255,0,0));

            al_draw_filled_rectangle(2*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE, 3*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(i+1))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
            al_draw_filled_rectangle((MAX_SIZE_TABLE-2)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-i)*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-3)*PIXEL_GAME_SIZE, (((MAX_SIZE_TABLE-(i+1))*PIXEL_GAME_SIZE)+1), al_map_rgb(255,0,0));
        }

        // vertical walls
        if(i >= 4 && i <= 15){
            if(i >= 4 && i <= 8){
                al_draw_filled_rectangle(i*PIXEL_GAME_SIZE, 7*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), 8*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
                al_draw_filled_rectangle(i*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), (MAX_SIZE_TABLE-8)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
            }

            if(i >= 10 && i <= 14){
                al_draw_filled_rectangle(i*PIXEL_GAME_SIZE, 7*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), 8*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
                al_draw_filled_rectangle(i*PIXEL_GAME_SIZE, (MAX_SIZE_TABLE-7)*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), (MAX_SIZE_TABLE-8)*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
            }

            if(i >= 4 && i <= 14)
                al_draw_filled_rectangle(i*PIXEL_GAME_SIZE, 9*PIXEL_GAME_SIZE, (((i+1)*PIXEL_GAME_SIZE)-1), 10*PIXEL_GAME_SIZE, al_map_rgb(255,0,0));
        }
    }

}

// desenhando as comidas
void Display::drawSpritesFood(int sprite){
    if(sprite == 1){
        Display::food = al_load_bitmap("./assets/smallFood.png");
    }
    if(sprite == 2){
        Display::food = al_load_bitmap("./assets/bigFood.png");
    }

    for(int i=1; i<MAX_SIZE_TABLE-1;i++){
        for(int j=1; j<MAX_SIZE_TABLE-1; j++){
            if(Rules::tableSQMS[j][i] == 1)
                al_draw_bitmap(Display::food, i*PIXEL_GAME_SIZE, j*PIXEL_GAME_SIZE, ALLEGRO_FLIP_HORIZONTAL);
        }
    }
}

//desenhando fantasmas
void Display::drawGhost(){
    if(ghost1->getPositionMove() == 1)
        ghost1->ghost = al_load_bitmap("./assets/ghostRedDown.png");
    if(ghost1->getPositionMove() == 2)
        ghost1->ghost = al_load_bitmap("./assets/ghostRedLeft.png");
    if(ghost1->getPositionMove() == 3)
        ghost1->ghost = al_load_bitmap("./assets/ghostRedUp.png");
    if(ghost1->getPositionMove() == 4)
        ghost1->ghost = al_load_bitmap("./assets/ghostRedRight.png");

    al_draw_bitmap(ghost1->ghost, ghost1->getPosX(), ghost1->getPosY(), ALLEGRO_FLIP_HORIZONTAL);

}

// desenhando o Pacman
void Display::drawPacman(int sprite, int move){

    if(move == 1){

        if(sprite == 1){
            Display::pacman = al_load_bitmap("./assets/pacmanDown1.png");
        }else{
            Display::pacman = al_load_bitmap("./assets/pacmanDown2.png");
        }
    }else if(move == 2){

        if(sprite == 1){
            Display::pacman = al_load_bitmap("./assets/pacmanRight1.png");
        }else{
            Display::pacman = al_load_bitmap("./assets/pacmanRight2.png");
        }
    }else if(move == 3){

        if(sprite == 1){
            Display::pacman = al_load_bitmap("./assets/pacmanUp1.png");
        }else{
            Display::pacman = al_load_bitmap("./assets/pacmanUp2.png");
        }
    }else{

        if(sprite == 1){
            Display::pacman = al_load_bitmap("./assets/pacmanLeft1.png");
        }else{
            Display::pacman = al_load_bitmap("./assets/pacmanLeft2.png");
        }
    }

    al_draw_bitmap(Display::pacman, Entities::getPosX(), Entities::getPosY(), ALLEGRO_FLIP_VERTICAL);
}

void Display::drawScore(int score){
    al_draw_textf(fontDefault, al_map_rgb(255,255,255), PIXEL_GAME_SIZE*(MAX_SIZE_TABLE-4), 6, NULL, "Pontos: %d", score);
}
