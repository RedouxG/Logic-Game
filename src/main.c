#include "game/game_loop.h"

// Entry point for the program
int main(int argc, char *argv[])
{
    start_game_loop();

    // Dummy action to skip warnings about unused variables
    for (int i=0;i<argc;i++) { printf("%s\n",argv[i]); }
    
    return EXIT_SUCCESS;
}