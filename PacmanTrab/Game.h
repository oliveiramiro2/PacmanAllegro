#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Display.h"

class Game : public Display{
public:
    void setGaming(bool value);
    bool getGaming();
    void setDraw(bool value);
    bool getDraw();
    void loopGame();
    int count = 0;
    ALLEGRO_TIMER *time = NULL;
    ALLEGRO_EVENT_QUEUE *queueEvent = NULL;
    ALLEGRO_EVENT events;
    Game();
    ~Game();
private:
    bool gaming = false;
    bool draw = false;
};

#endif // GAME_H_INCLUDED
