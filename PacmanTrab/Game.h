#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Display.h"
#include "Rules.h"

class Game : public Display, public Rules{
public:
    void setPlaying(bool value);
    bool getPlaying();
    void setDraw(bool value);
    bool getDraw();
    void loopGame();
    int count = 0;
    int nextMove = 2;
    ALLEGRO_TIMER *time = NULL;
    ALLEGRO_EVENT_QUEUE *queueEvent = NULL;
    ALLEGRO_EVENT events;
    Game();
    ~Game();
private:
    bool playing = false;
    bool draw = false;
    bool checkNextSQM(int action, int checkNextMove = 0);
};

#endif // GAME_H_INCLUDED
