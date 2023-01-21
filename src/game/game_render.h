#pragma once
#ifndef GAME_RENDER
#define GAME_RENDER

// -------------------------------------------------
// DEPENDENCIES
// -------------------------------------------------

#include "global_data.h"

// -------------------------------------------------
// FUNCTIONS
// -------------------------------------------------

void game_render_player(SDL_Renderer *renderer, const vec2 pos);

void game_render_map(SDL_Renderer *renderer, const i32 *mapToRender,
    const u32 mapWidth, const u32 mapHeight);

void game_render_tile(i32 tileID, SDL_Renderer *renderer, SDL_Rect *rect);

void game_render_texture(SDL_Renderer *renderer, const SDL_Rect *rectCrop, const SDL_Rect *rect,
    const char *imagePath);

#endif