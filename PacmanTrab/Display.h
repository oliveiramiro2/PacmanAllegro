#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Display{
public:
    ALLEGRO_DISPLAY *display = NULL;
    void drawWall();
    Display();
    ~Display();
private:
};

#endif // DISPLAY_H_INCLUDED
