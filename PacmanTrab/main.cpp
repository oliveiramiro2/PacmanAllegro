#include <stdio.h>
#include "Game.h"

using namespace std;

int main(){
    Game *game = new Game();

    free(game);
	return 0;
}
