#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED
#include "Entities.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

class Ghost : public Entities {
public:
    ALLEGRO_BITMAP *ghost = al_load_bitmap("./assets/bigFood.png");
    Ghost(int type);
    ~Ghost();
private:

};


#endif // GHOST_H_INCLUDED
