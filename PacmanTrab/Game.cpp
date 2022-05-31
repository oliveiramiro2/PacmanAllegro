#include <iostream>
#include "Game.h"

using namespace std;

#define FPS 60
#define SPEED 1

Game::Game() : Display(){
    queueEvent = al_create_event_queue();
    time = al_create_timer(1.0 / FPS);

    //install
    al_install_keyboard();
    al_install_mouse();
    al_start_timer(time);


    //register events
    al_register_event_source(queueEvent, al_get_timer_event_source(time));
    al_register_event_source(queueEvent, al_get_display_event_source(Display::display));
    al_register_event_source(queueEvent, al_get_keyboard_event_source());
    al_register_event_source(queueEvent, al_get_mouse_event_source());


    Game::setPlaying(true);
    Game::loopGame();

    //destoy
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

        if(Game::events.type == ALLEGRO_EVENT_KEY_DOWN){

            if(Game::events.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                Game::setPlaying(false);
            }else if(Game::events.type == ALLEGRO_EVENT_TIMER){
                Display::drawSpritesFood(1);
                Display::drawWall();
                al_flip_display();
            }
        }

        if(Game::events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){

            Game::setPlaying(false);
        }

        if(al_is_event_queue_empty(queueEvent) && Game::getDraw()){

            Display::drawSpritesFood(1);
            Display::drawWall();
            Display::drawPacman(1);
            al_flip_display();
            Game::setDraw(false);
        }

        if(count == 20 || count == 40){

            al_clear_to_color(al_map_rgb(255,255,255));
            if(count == 20){
                Display::drawSpritesFood(2);
                Display::drawWall();
                Display::drawPacman(2);
                al_flip_display();
            }
            if(count == 40){
                Display::drawSpritesFood(1);
                Display::drawWall();
                Display::drawPacman(1);
                al_flip_display();
                Game::count = 0;
            }
        }
        Entities::setPosX(Entities::getPosX() + SPEED);

        Game::count++;
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
