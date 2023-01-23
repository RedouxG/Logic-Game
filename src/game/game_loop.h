// -------------------------------------------------
// Main game loop
// -------------------------------------------------

#pragma once
#ifndef GAME_LOOP
#define GAME_LOOP

// -------------------------------------------------
// DEPENDENCIES
// -------------------------------------------------

#include "global_data.h"
#include "game_render.h"
#include "game_logic.h"

// -------------------------------------------------
// Functions
// -------------------------------------------------

// Initializes SDL window
SDL_Window* init_window();

// Initializes SDL renderer
SDL_Renderer* init_renderer(SDL_Window *window);

// Game loop
void start_game_loop();

// Function handles pressed keys (sends coresponding key pressed signals ti game_logic module)
void handle_key_event(const u8* keysPressed);

#endif