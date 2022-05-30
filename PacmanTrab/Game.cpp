#include <iostream>
#include "Game.h"
#include "Display.h"

using namespace std;

#define FPS 60

Game::Game() : Display(){
    Game::queueEvent = al_create_event_queue();
    Game::time = al_create_timer(1.0 / FPS);

    //register events
    al_register_event_source(Game::queueEvent, al_get_timer_event_source(Game::time));
    al_register_event_source(Game::queueEvent, al_get_display_event_source(Display::display));
    al_register_event_source(Game::queueEvent, al_get_keyboard_event_source());
    al_register_event_source(Game::queueEvent, al_get_mouse_event_source());

    //install
    al_install_keyboard();
    al_install_mouse();
    al_start_timer(Game::time);

    Game::setGaming(true);
    Game::loopGame();

    //destoy
    al_destroy_event_queue(Game::events);
    al_destroy_bitmap(Display::food); //Destroi a comida
    al_destroy_display(Display::display); //Destroi a tela

}

void Game::loopGame(){
    while(Game::getGaming()){
        al_wait_for_event(Game::queueEvent, &Game::events);

        if(Game::events.type == ALLEGRO_EVENT_KEY_DOWN){
            if(Game::events.keyboard.keycode == ALLEGRO_KEY_SPACE){
                Game::setGaming(false);
            }else if(Game::events.type == ALLEGRO_EVENT_TIMER){
                Display.drawSpritesFood();
                Display::drawWall();
                al_flip_display();
            }

            if(al_is_event_queue_empty(Game::queueEvent)){
                Display.drawSpritesFood();
                Display::drawWall();
                al_flip_display();
            }
        }

    }
}

void Game::setGaming(bool value){
    Game::gaming = value;
}

bool Game::getGaming(){
    return Game::gaming;
}
