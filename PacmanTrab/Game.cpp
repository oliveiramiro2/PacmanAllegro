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
            Display::drawGhost();
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
                Display::drawGhost();
                al_flip_display();
            }
            if(count == 40){
                Display::drawSpritesFood(1);
                Display::drawWall();
                Display::drawPacman(1, Game::getPositionMove());
                Display::drawScore(scorePlayer);
                Display::drawGhost();
                al_flip_display();
                Game::count = 0;
            }
        }

        // trocando direcao dos fantasmas
        if(ghost1->getPosY() % PIXEL_GAME_SIZE == 0 && ghost1->getPosX() % PIXEL_GAME_SIZE == 0){
            ghost1->checkSide(Rules::tableSQMS, ghost1->getPosX() / PIXEL_GAME_SIZE, ghost1->getPosY() / PIXEL_GAME_SIZE, Entities::getPosX() / PIXEL_GAME_SIZE, Entities::getPosY() / PIXEL_GAME_SIZE);
        }
        if(ghost2->getPosY() % PIXEL_GAME_SIZE == 0 && ghost2->getPosX() % PIXEL_GAME_SIZE == 0){
            ghost2->checkSide(Rules::tableSQMS, ghost2->getPosX() / PIXEL_GAME_SIZE, ghost2->getPosY() / PIXEL_GAME_SIZE, Entities::getPosX() / PIXEL_GAME_SIZE, Entities::getPosY() / PIXEL_GAME_SIZE);
        }
        if(ghost3->getPosY() % PIXEL_GAME_SIZE == 0 && ghost3->getPosX() % PIXEL_GAME_SIZE == 0){
            ghost3->checkSide(Rules::tableSQMS, ghost3->getPosX() / PIXEL_GAME_SIZE, ghost3->getPosY() / PIXEL_GAME_SIZE, Entities::getPosX() / PIXEL_GAME_SIZE, Entities::getPosY() / PIXEL_GAME_SIZE);
        }
        if(ghost4->getPosY() % PIXEL_GAME_SIZE == 0 && ghost4->getPosX() % PIXEL_GAME_SIZE == 0){
            ghost4->checkSide(Rules::tableSQMS, ghost4->getPosX() / PIXEL_GAME_SIZE, ghost4->getPosY() / PIXEL_GAME_SIZE, Entities::getPosX() / PIXEL_GAME_SIZE, Entities::getPosY() / PIXEL_GAME_SIZE);
        }

        // movendo fantasmas
        if(this->count % 3 == 0){
            if(ghost1->getPositionMove() == 1){
                this->ghost1->setPosY(ghost1->getPosY() - SPEED);
            }else if(ghost1->getPositionMove() == 2){
                ghost1->setPosX(ghost1->getPosX() + SPEED);
            }else if(ghost1->getPositionMove() == 3){
                ghost1->setPosY(ghost1->getPosY() + SPEED);
            }else if(ghost1->getPositionMove() == 4){
                ghost1->setPosX(ghost1->getPosX() - SPEED);
            }

            if(ghost2->getPositionMove() == 1){
                this->ghost2->setPosY(ghost2->getPosY() - SPEED);
            }else if(ghost2->getPositionMove() == 2){
                ghost2->setPosX(ghost2->getPosX() + SPEED);
            }else if(ghost2->getPositionMove() == 3){
                ghost2->setPosY(ghost2->getPosY() + SPEED);
            }else if(ghost2->getPositionMove() == 4){
                ghost2->setPosX(ghost2->getPosX() - SPEED);
            }

            if(ghost3->getPositionMove() == 1){
                this->ghost3->setPosY(ghost3->getPosY() - SPEED);
            }else if(ghost3->getPositionMove() == 2){
                ghost3->setPosX(ghost3->getPosX() + SPEED);
            }else if(ghost3->getPositionMove() == 3){
                ghost3->setPosY(ghost3->getPosY() + SPEED);
            }else if(ghost3->getPositionMove() == 4){
                ghost3->setPosX(ghost3->getPosX() - SPEED);
            }

            if(ghost4->getPositionMove() == 1){
                this->ghost4->setPosY(ghost4->getPosY() - SPEED);
            }else if(ghost4->getPositionMove() == 2){
                ghost4->setPosX(ghost4->getPosX() + SPEED);
            }else if(ghost4->getPositionMove() == 3){
                ghost4->setPosY(ghost4->getPosY() + SPEED);
            }else if(ghost4->getPositionMove() == 4){
                ghost4->setPosX(ghost4->getPosX() - SPEED);
            }
        }

        // checando colisao
        if(
            ghost1->getPosY() / PIXEL_GAME_SIZE == Entities::getPosY() / PIXEL_GAME_SIZE && ghost1->getPosX() / PIXEL_GAME_SIZE == Entities::getPosX() / PIXEL_GAME_SIZE ||
            ghost2->getPosY() / PIXEL_GAME_SIZE == Entities::getPosY() / PIXEL_GAME_SIZE && ghost2->getPosX() / PIXEL_GAME_SIZE == Entities::getPosX() / PIXEL_GAME_SIZE ||
            ghost3->getPosY() / PIXEL_GAME_SIZE == Entities::getPosY() / PIXEL_GAME_SIZE && ghost3->getPosX() / PIXEL_GAME_SIZE == Entities::getPosX() / PIXEL_GAME_SIZE ||
            ghost4->getPosY() / PIXEL_GAME_SIZE == Entities::getPosY() / PIXEL_GAME_SIZE && ghost4->getPosX() / PIXEL_GAME_SIZE == Entities::getPosX() / PIXEL_GAME_SIZE
          )
            this->setPlaying(false);

        // movimentado o pacman 65 pixeis por segundo
        if(Game::checkNextSQM(0) && (!Game::checkNextSQM(1, nextMove) || nextMove == Entities::getPositionMove())){ // checando disponibilidade

            if(Entities::getPosX() >= 36 && Entities::getPosY() >= 36){
                if(Entities::getPositionMove() == 1)
                    Entities::setPosY(Entities::getPosY() - SPEED);
                else if(Entities::getPositionMove() == 2)
                    Entities::setPosX(Entities::getPosX() + SPEED);
                else if(Entities::getPositionMove() == 3)
                    Entities::setPosY(Entities::getPosY() + SPEED);
                else if(Entities::getPositionMove() == 4)
                    Entities::setPosX(Entities::getPosX() - SPEED);
            }else{
                if(Entities::getPosX() >= 36){
                    if(Entities::getPositionMove() == 2)
                        Entities::setPosX(Entities::getPosX() + SPEED);
                    else if(Entities::getPositionMove() == 3)
                        Entities::setPosY(Entities::getPosY() + SPEED);
                    else if(Entities::getPositionMove() == 4)
                        Entities::setPosX(Entities::getPosX() - SPEED);
                }else{
                    if(Entities::getPositionMove() == 1)
                        Entities::setPosY(Entities::getPosY() - SPEED);
                    else if(Entities::getPositionMove() == 2)
                        Entities::setPosX(Entities::getPosX() + SPEED);
                    else if(Entities::getPositionMove() == 3)
                        Entities::setPosY(Entities::getPosY() + SPEED);
                }
            }
        }else if(nextMove != Entities::getPositionMove() && Game::checkNextSQM(1, nextMove)){
            if(Display::getPosY() % 35 == 0 && Display::getPosX() % 35 == 0 && Game::checkNextSQM(1, nextMove))
                Entities::setPositionMove(nextMove);
            else{

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

        // checando win
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
            if(Rules::tableSQMS[(Display::getPosY())/PIXEL_GAME_SIZE][(Display::getPosX())/PIXEL_GAME_SIZE] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
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
            if(Rules::tableSQMS[(Display::getPosY())/PIXEL_GAME_SIZE][(Display::getPosX())/PIXEL_GAME_SIZE] >= 1 && (Display::getPosY() % 35 == 0 || Display::getPosX() % 35 == 0)){
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
