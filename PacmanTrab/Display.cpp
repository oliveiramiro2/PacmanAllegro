#include <iostream>
#include <allegro5/allegro_native_dialog.h>
#include "Display.h"

using namespace std;

Display::Display(){
    if(!al_init()) {                                                                                    // verifica se a allegro iniciou normalmente
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o Allegro",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    Display::display = al_create_display(1200, 700);

    if(!display) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o display!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
   }

   al_clear_to_color(al_map_rgb(0,155,155));
   al_flip_display();

   Display::drawWall();

   al_rest(2); //Tempo que a tela fica ativa (em segundos)

   al_destroy_display(display); //Destroi a tela
}
