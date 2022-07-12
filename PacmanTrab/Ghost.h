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
    bool checkMove(int table[19][19]);
    void checkSide(int table[19][19], int x, int y);
    Ghost(int type);
    ~Ghost();
private:

};


#endif // GHOST_H_INCLUDED
