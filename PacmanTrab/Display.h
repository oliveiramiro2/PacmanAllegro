#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "Entities.h"
#include "Rules.h"
#include "Ghost.h"

class Display : public Entities, public Rules{
public:
    Ghost *ghost1 = new Ghost(1);
    Ghost *ghost2 = new Ghost(2);
    Ghost *ghost3 = new Ghost(3);
    Ghost *ghost4 = new Ghost(4);
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *food = NULL;
    ALLEGRO_BITMAP *pacman = NULL;
    ALLEGRO_FONT *fontDefault = NULL;
    void drawPacman(int sprite, int move);
    void drawWall();
    void drawSpritesFood(int sprite);
    void drawScore(int score = 0);
    void drawGhost();
    Display();
    ~Display();
private:
};

#endif // DISPLAY_H_INCLUDED
