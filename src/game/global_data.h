// -------------------------------------------------
// Included in all files that need access to game data
// -------------------------------------------------

#pragma once
#ifndef GAME_DATA
#define GAME_DATA

// -------------------------------------------------
// DEPENDENCIES
// -------------------------------------------------

#include "global.h"

// -------------------------------------------------
// GLOBAL DATA
// -------------------------------------------------

// Window constant values
typedef struct _global_window {
    const char *NAME;
    const i32 WIDTH;
    const i32 HEIGHT;
} _global_window;


// Tiles enum
typedef enum {
    TILE_FLOOR = 0, 
    TILE_WALL = 1, 
    TILE_BOULDER = 2,
    TILE_OBSTACLE = 3, 
    TILE_WIN = 8,
    TILE_PLAYER = 9
} TILE_TYPES;

// Data regardnig game map
typedef struct _game_map_data {
    const i32 TILE_WIDTH;
    const i32 TILE_HEIGHT;
    const i32 WIDTH;
    const i32 HEIGHT;
    u32 MapsNumber;
} _game_map_data;


// State of the game (player position ect.)
typedef struct _game_state {
    u32 CurrentLevel;
    i32 *CurrentMap;
    vec2 PlayerPos;
    vec2 WinPos;
    bool Won;
} _game_state;


// Global access point to data meant to be accessible globaly
typedef struct _global {
    const _global_window WINDOW;
    const u32 FRAME_DELAY;
    _game_map_data MAP_DATA;
    _game_state GameState;
    u32 DelayFrames;
} _global;

// Access point to all global data (define)
extern _global GLOBAL;

// -------------------------------------------------
// FUNCTIONS
// -------------------------------------------------

// Loads a map from ./levels file
// Level format is 9x9 matrix of chars converted to numbers
// Numbers in matrix corespond to tile IDs (look TILE_TYPES enum)
bool game_load_map(u32 level);


// Counts how many levels are in ./levels folder
u32 count_levels_in_dir();

#endif