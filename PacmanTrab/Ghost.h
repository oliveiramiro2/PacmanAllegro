#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED
#include <cstdlib>
#include <ctime>
#include "Entities.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

class Ghost : public Entities {
public:
    ALLEGRO_BITMAP *ghost = NULL;
    void checkSide(int table[19][19], int x, int y, int pacmanX, int pacmanY);
    void changeDirection(int table[19][19], int x, int y, int pacmanX, int pacmanY);
    void setTypeStalker(int value);
    int getTypeStalker();
    int xRest, yRest;
    Ghost(int type);
    ~Ghost();
private:
    int typeStalker;
};


#endif // GHOST_H_INCLUDED
