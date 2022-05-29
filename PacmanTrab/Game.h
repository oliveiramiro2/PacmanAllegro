#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Display.h"

class Game : public Display{
public:
    void setTeste(int value);
    int getTeste();
    Game();
    ~Game();
private:
    int teste;
};

#endif // GAME_H_INCLUDED
