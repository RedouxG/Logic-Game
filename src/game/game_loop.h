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

SDL_Window* init_window();

SDL_Renderer* init_renderer(SDL_Window *window);

// Game loop
void start_game_loop();

// Function handles pressed keys
void handle_key_event(const u8* keysPressed);

#endif