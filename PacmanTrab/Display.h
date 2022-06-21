#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Entities.h"
#include "Rules.h"

class Display : public Entities, public Rules{
public:
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *food = NULL;
    ALLEGRO_BITMAP *pacman = NULL;
    void drawPacman(int sprite, int move);
    void drawWall();
    void drawSpritesFood(int sprite);
    Display();
private:
};

#endif // DISPLAY_H_INCLUDED
