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

void game_set_tile_at(i32 tileID, vec2 direction);

void game_move_player(vec2 direction);

bool game_move_boulder(vec2 fromPos, vec2 toPos);


#endif