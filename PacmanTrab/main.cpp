#include <stdio.h>
//#include "Display.h"
#include "Game.h"

using namespace std;

int main(){
    Game *game = new Game();
    //Display *d = new Display();
    //Game    *g = new Game();

    free(game);
	return 0;
}
