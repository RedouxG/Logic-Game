// -------------------------------------------------
// Renders textures to the window
// -------------------------------------------------

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

// Renders player sprite to coresponding position
void game_render_player(SDL_Renderer *renderer, const vec2 pos);

// Renders currently loaded map to the window
void game_render_map(SDL_Renderer *renderer, const i32 *mapToRender,
    const u32 mapWidth, const u32 mapHeight);

// Renders singular tile on a given position
void game_render_tile(i32 tileID, SDL_Renderer *renderer, SDL_Rect *rect);

// Renders given texture on a given position
void game_render_texture(SDL_Renderer *renderer, const SDL_Rect *rectCrop, const SDL_Rect *rect,
    const char *imagePath);

// Renders victory screen
void game_render_win(SDL_Renderer *renderer);

#endif