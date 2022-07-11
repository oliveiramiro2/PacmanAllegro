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
}

Game::~Game(){
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
                if(Display::getPosY() % 35 == 0 && Display::getPosX() % 35 == 0 && Game::checkNextSQM(1, 3)){
                    Entities::setPositionMove(3);
                    nextMove = 3;
                }else
                    nextMove = 3;
            }else if(Game::events.keyboard.keycode == ALLEGRO_KEY_RIGHT){ // direita
                if(Display::getPosY() % 35 == 0 && Display::getPosX() % 35 == 0 && Game::checkNextSQM(1, 2)){
                    Entities::setPositionMove(2);
                    nextMove = 2;
                }else
                    nextMove = 2;
            }else if(Game::events.keyboard.keycode == ALLEGRO_KEY_UP){ // cima
                if(Display::getPosY() % 35 == 0 && Display::getPosX() % 35 == 0 && Game::checkNextSQM(1, 1)){
                    Entities::setPositionMove(1);
                    nextMove = 1;
                }else
                    nextMove = 1;
            }else if(Game::events.keyboard.keycode == ALLEGRO_KEY_LEFT){ // esquerda
                if(Display::getPosY() % 35 == 0 && Display::getPosX() % 35 == 0 && Game::checkNextSQM(1, 4)){
                    Entities::setPositionMove(4);
                    nextMove = 4;
                }else
                    nextMove = 4;
            }else if(Game::events.type == ALLEGRO_EVENT_TIMER){
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
            Display::drawScore(scorePlayer);
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
                Display::drawScore(scorePlayer);
                al_flip_display();
            }
            if(count == 40){
                Display::drawSpritesFood(1);
                Display::drawWall();
                Display::drawPacman(1, Game::getPositionMove());
                Display::drawScore(scorePlayer);
                al_flip_display();
                Game::count = 0;
            }
        }

        ghost1->setPosX(ghost1->getPosX()+SPEED);
        ghost2->setPosY(ghost2->getPosY()+SPEED);
        ghost3->setPosX(ghost3->getPosX()+SPEED);
        ghost4->setPosY(ghost4->getPosY()-SPEED);


        // movimentado o pacman 65 pixeis por segundo
        if(Game::checkNextSQM(0) && (!Game::checkNextSQM(1, nextMove) || nextMove == Entities::getPositionMove())){ // checando disponibilidade

            if(Entities::getPosX() > 34 && Entities::getPosY() > 34){
                if(Entities::getPositionMove() == 1)
                    Entities::setPosY(Entities::getPosY() - SPEED);
                else if(Entities::getPositionMove() == 2)
                    Entities::setPosX(Entities::getPosX() + SPEED);
                else if(Entities::getPositionMove() == 3)
                    Entities::setPosY(Entities::getPosY() + SPEED);
                else if(Entities::getPositionMove() == 4)
                    Entities::setPosX(Entities::getPosX() - SPEED);
            }
        }else if(nextMove != Entities::getPositionMove() && Game::checkNextSQM(1, nextMove)){
            if(Display::getPosY() % 35 == 0 && Display::getPosX() % 35 == 0 && Game::checkNextSQM(1, nextMove))
                Entities::setPositionMove(nextMove);
            else{

            if(Entities::getPosX() > 34 && Entities::getPosY() > 34){
                if(Entities::getPositionMove() == 1)
                    Entities::setPosY(Entities::getPosY() - SPEED);
                else if(Entities::getPositionMove() == 2)
                    Entities::setPosX(Entities::getPosX() + SPEED);
                else if(Entities::getPositionMove() == 3)
                    Entities::setPosY(Entities::getPosY() + SPEED);
                else if(Entities::getPositionMove() == 4)
                    Entities::setPosX(Entities::getPosX() - SPEED);
            }
            }

        }

        // check win
        if(scorePlayer == 176)
            Game::setPlaying(false);

        // contador para desenhos na tela
        Game::count++;
    }
}

// funcao que consulta a matriz de SQM do tabuleiro e checa se pode movimentar
bool Game::checkNextSQM(int action, int checkNextMove){
    if(action == 0){
        if(Rules::tableSQMS[Display::getPosY()/PIXEL_GAME_SIZE][Display::getPosX()/PIXEL_GAME_SIZE] != 0 && Rules::tableSQMS[Display::getPosY()/PIXEL_GAME_SIZE][Display::getPosX()/PIXEL_GAME_SIZE] != 2){
            scorePlayer++;
            Rules::tableSQMS[Display::getPosY()/PIXEL_GAME_SIZE][Display::getPosX()/PIXEL_GAME_SIZE] = 2;
        }

        if(Entities::getPositionMove() == 1){
            if(Rules::tableSQMS[(Display::getPosY())/PIXEL_GAME_SIZE-1][(Display::getPosX())/PIXEL_GAME_SIZE] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
                return true;
            }else
                return false;
        }else if(Entities::getPositionMove() == 2){
            if(Rules::tableSQMS[((Display::getPosY())/PIXEL_GAME_SIZE)][Display::getPosX()/PIXEL_GAME_SIZE+1] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
                return true;
            }
            else
                return false;
        }else if(Entities::getPositionMove() == 3){
            if(Rules::tableSQMS[Display::getPosY()/PIXEL_GAME_SIZE+1][(Display::getPosX()/PIXEL_GAME_SIZE)] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
                return true;
            }
            else
                return false;
        }else if(Entities::getPositionMove() == 4){
            if(Rules::tableSQMS[(Display::getPosY())/PIXEL_GAME_SIZE][(Display::getPosX())/PIXEL_GAME_SIZE-1] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
                return true;
            }
            else
                return false;
        }
    }else{
        if(checkNextMove == 1){
            if(Rules::tableSQMS[((Display::getPosY())/PIXEL_GAME_SIZE)-1][(Display::getPosX())/PIXEL_GAME_SIZE] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
                return true;
            }else
                return false;
        }else if(checkNextMove == 2){
            if(Rules::tableSQMS[(Display::getPosY())/PIXEL_GAME_SIZE][(Display::getPosX()/PIXEL_GAME_SIZE+1)] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
                return true;
            }
            else
                return false;
        }else if(checkNextMove == 3){
            if(Rules::tableSQMS[(Display::getPosY()/PIXEL_GAME_SIZE+1)][(Display::getPosX())/PIXEL_GAME_SIZE] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
                return true;
            }
            else
                return false;
        }else if(checkNextMove == 4){
            if(Rules::tableSQMS[(Display::getPosY())/PIXEL_GAME_SIZE][((Display::getPosX())/PIXEL_GAME_SIZE)-1] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
                return true;
            }
            else
                return false;
        }
    }

    return false;
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
