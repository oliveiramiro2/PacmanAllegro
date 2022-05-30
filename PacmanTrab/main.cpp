#include <stdio.h>
#include "Game.h"
//#include "Display.h"

using namespace std;

int main(){
    Game *game = new Game();

    free(game);
	return 0;
}
