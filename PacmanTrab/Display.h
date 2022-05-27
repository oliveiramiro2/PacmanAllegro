#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

class Display{
public:
    ALLEGRO_DISPLAY *display = NULL;
    void drawWall();
    void drawSpritesFood();
    Display();
    ~Display();
private:
};

#endif // DISPLAY_H_INCLUDED
