#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Display.h"

class Game : public Display{
public:
    void setGaming(bool value);
    bool getGaming();
    void loopGame();
    ALLEGRO_TIMER *time = NULL;
    ALLEGRO_EVENT_QUEUE *queueEvent = NULL;
    ALLEGRO_EVENT *events= NULL;
    Game();
    ~Game();
private:
    bool gaming = false;
};

#endif // GAME_H_INCLUDED
