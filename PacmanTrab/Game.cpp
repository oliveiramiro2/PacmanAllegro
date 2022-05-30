#include <iostream>
#include "Game.h"
#include "Display.h"

using namespace std;

#define FPS 60

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


    Game::setGaming(true);
    Game::loopGame();

    //destoy
    al_destroy_event_queue(queueEvent); // Destroi fila de eventos
    al_destroy_bitmap(Display::food); //Destroi a comida
    al_destroy_display(Display::display); //Destroi a tela

}

void Game::loopGame(){
    Game::setDraw(true);
    while(Game::getGaming()){
        al_wait_for_event(queueEvent, &events);

        if(Game::events.type == ALLEGRO_EVENT_KEY_DOWN){
            if(Game::events.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                Game::setGaming(false);
            }else if(Game::events.type == ALLEGRO_EVENT_TIMER){
                Display::drawSpritesFood();
                Display::drawWall();
                al_flip_display();
            }
        }

        if(Game::events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            Game::setGaming(false);
        }

        if(al_is_event_queue_empty(queueEvent) && Game::getDraw()){
            Display::drawSpritesFood();
            Display::drawWall();
            al_flip_display();
            Game::setDraw(false);
        }

    }
}

void Game::setGaming(bool value){
    Game::gaming = value;
}

bool Game::getGaming(){
    return Game::gaming;
}

void Game::setDraw(bool value){
    Game::draw = value;
}

bool Game::getDraw(){
    return Game::draw;
}
