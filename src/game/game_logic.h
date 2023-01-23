// -------------------------------------------------
// Handles logic of the game
// -------------------------------------------------

#pragma once
#ifndef GAME_LOGIC
#define GAME_LOGIC

// -------------------------------------------------
// DEPENDENCIES
// -------------------------------------------------

#include "global_data.h"
#include "game_render.h"

// -------------------------------------------------
// Functions
// -------------------------------------------------

// Changes ID of of a tile on a given position
void game_set_tile_at(i32 tileID, vec2 pos);

// Moves player in a given direction
void game_move_player(vec2 direction);

// Moves boulder in a given direction
bool game_move_boulder(vec2 fromPos, vec2 toPos);

// Game win, shows game win sprite
void game_win();

// Restarts current level
void game_restart_level();

#endif