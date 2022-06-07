#include <iostream>
#include <stdlib.h>
#include "Game.h"

using namespace std;

#define FPS 65
#define SPEED 1
#define PIXEL_GAME_SIZE 35

Game::Game() : Display(){
    queueEvent = al_create_event_queue();
    time = al_create_timer(1.0 / FPS);

    // instalando componentes de/para eventos
    al_install_keyboard();
    al_install_mouse();
    al_start_timer(time);


    // iniciando registro de eventos
    al_register_event_source(queueEvent, al_get_timer_event_source(time));
    al_register_event_source(queueEvent, al_get_display_event_source(Display::display));
    al_register_event_source(queueEvent, al_get_keyboard_event_source());
    al_register_event_source(queueEvent, al_get_mouse_event_source());

    // iniciando loop do jogo
    Game::setPlaying(true);
    Game::loopGame();

    // desalocando ponteiros
    al_destroy_event_queue(queueEvent); // Destroi fila de eventos
    al_destroy_bitmap(Display::food); //Destroi a comida
    al_destroy_bitmap(Display::pacman); //Destroi o pacman
    al_destroy_display(Display::display); //Destroi a tela
    al_destroy_bitmap(Display::food); //Destroi a comida

}

void Game::loopGame(){
    Game::setDraw(true);
    while(Game::getPlaying()){

        al_wait_for_event(queueEvent, &events);

        // evento do teclado
        if(Game::events.type == ALLEGRO_EVENT_KEY_DOWN){
            // tecla Esc fecha o jogo
            if(Game::events.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                Game::setPlaying(false);
            }else if(Game::events.keyboard.keycode == ALLEGRO_KEY_DOWN){ // baixo
                Entities::setPositionMove(3);
            }else if(Game::events.keyboard.keycode == ALLEGRO_KEY_RIGHT){ // direita
                Entities::setPositionMove(2);
            }else if(Game::events.keyboard.keycode == ALLEGRO_KEY_UP){ // cima
                Entities::setPositionMove(1);
            }else if(Game::events.keyboard.keycode == ALLEGRO_KEY_LEFT){ // esquerda
                Entities::setPositionMove(4);
            }else if(Game::events.type == ALLEGRO_EVENT_TIMER){
                Display::drawSpritesFood(1);
                Display::drawWall();
                al_flip_display();
            }
        }

        // ativiando a funcao close da janela
        if(Game::events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){

            Game::setPlaying(false);
        }

        // se a fila estiver fazia desenhar na tela 1x
        if(al_is_event_queue_empty(queueEvent) && Game::getDraw()){

            Display::drawSpritesFood(1);
            Display::drawWall();
            Display::drawPacman(1, Game::getPositionMove());
            al_flip_display();
            Game::setDraw(false);
        }

        // desenhando o movimento da comida e do pacman 3x por segunda
        if(count == 20 || count == 40){

            // colocar um desenho em cima do outro gasta mais recurso da maquina?
            al_clear_to_color(al_map_rgb(255,255,255));
            if(count == 20){
                Display::drawSpritesFood(2);
                Display::drawWall();
                Display::drawPacman(2, Game::getPositionMove());
                al_flip_display();
            }
            if(count == 40){
                Display::drawSpritesFood(1);
                Display::drawWall();
                Display::drawPacman(1, Game::getPositionMove());
                al_flip_display();
                Game::count = 0;
            }
        }

        // movimentado o pacman 65 pixeis por segundo
        if(Game::checkNextSQM()){ // checando disponibilidade
            if(Entities::getPositionMove() == 1)
                Entities::setPosY(Entities::getPosY() - SPEED);
            else if(Entities::getPositionMove() == 2)
                Entities::setPosX(Entities::getPosX() + SPEED);
            else if(Entities::getPositionMove() == 3)
                Entities::setPosY(Entities::getPosY() + SPEED);
            else
                Entities::setPosX(Entities::getPosX() - SPEED);
        }


        // contador para desenhos na tela
        Game::count++;
    }
}

// funcao que consulta a matriz de SQM do tabuleiro e checa se pode movimentar
bool Game::checkNextSQM(){
    if(Entities::getPositionMove() == 1){
        if(Rules::tableSQMS[(Display::getPosY()+6)/PIXEL_GAME_SIZE][(Display::getPosX()+6)/PIXEL_GAME_SIZE] == 1){
            cout << (Display::getPosY()+6)/PIXEL_GAME_SIZE << " - " << (Display::getPosX()+6)/PIXEL_GAME_SIZE << endl;
            return true;
        }else
            return false;
    }else if(Entities::getPositionMove() == 2){
        if(Rules::tableSQMS[(Display::getPosY()+6)/PIXEL_GAME_SIZE][(Display::getPosX()+6)/PIXEL_GAME_SIZE+1] == 1){
            cout << (Display::getPosY()+6)/PIXEL_GAME_SIZE << " - " << (Display::getPosX()+6)/PIXEL_GAME_SIZE+1 << endl;
            return true;
        }
        else
            return false;
    }else if(Entities::getPositionMove() == 3){
        if(Rules::tableSQMS[(Display::getPosY()+6)/PIXEL_GAME_SIZE+1][(Display::getPosX()+6)/PIXEL_GAME_SIZE] == 1){
            cout << (Display::getPosY()+6)/PIXEL_GAME_SIZE+1 << " - " << (Display::getPosX()+6)/PIXEL_GAME_SIZE << endl;
            return true;
        }
        else
            return false;
    }else{
        if(Rules::tableSQMS[(Display::getPosY()+6)/PIXEL_GAME_SIZE][(Display::getPosX()+6)/PIXEL_GAME_SIZE] == 1){
            cout << (Display::getPosY()+6)/PIXEL_GAME_SIZE << " - " << (Display::getPosX()+6)/PIXEL_GAME_SIZE << endl;
            return true;
        }
        else
            return false;
    }
}

void Game::setPlaying(bool value){
    Game::playing = value;
}

bool Game::getPlaying(){
    return Game::playing;
}

void Game::setDraw(bool value){
    Game::draw = value;
}

bool Game::getDraw(){
    return Game::draw;
}
