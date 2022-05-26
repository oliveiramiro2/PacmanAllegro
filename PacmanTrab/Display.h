#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "Wall.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Display: public Wall{
public:
    ALLEGRO_DISPLAY *display = NULL;
    Display();
private:
};

#endif // DISPLAY_H_INCLUDED
