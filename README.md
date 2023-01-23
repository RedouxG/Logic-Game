About
-----
Small logic game made in SDL2

Controls:
- W - Move up
- A - Move left
- S - Move down
- D - Move right
- R - Restart level

Building
-----------
Building the game requires: 
 - MinGw (gcc, make)
 - [SDL2](https://github.com/libsdl-org/SDL/releases/tag/release-2.26.2) and [SDL2_image](https://github.com/libsdl-org/SDL_image/releases/tag/release-2.6.2) library. (both devel-mingw x86_64 version)

To setup compilation: 
- Move all headers (include) to src/include directory from both libraries.
- Move all .a files into src/lib
- Move all .dll files to the project root directory

Compilation:
- Run `make -f build.mk` command
