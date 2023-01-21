#include "global_data.h"

// -------------------------------------------------
// GLOBAL
// -------------------------------------------------

_global GLOBAL = {
    .WINDOW = {
        .NAME = "TEST",
        .WIDTH = 512, 
        .HEIGHT = 512,
    },
    .MAP_DATA = {
        .HEIGHT = 8,
        .WIDTH = 8,
        .TILE_HEIGHT = 64,
        .TILE_WIDTH = 64,
        .MapList = NULL,
    },
    .GameState = {
        .CurrentLevel = 0,
        .CurrentMap = NULL,
    },
};

// -------------------------------------------------
// MAPS
// -------------------------------------------------

const u32 MAPS_NUMBER = 1;

const i32 GAME_MAP1[8][8] = {
    {1,1,1,1,1,1,1,1},
    {1,9,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,2,0,0,0,1},
    {1,0,0,2,0,2,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1},
};

// -------------------------------------------------
// FUNCTIONS
// -------------------------------------------------

void init_game_data()
{
    GLOBAL.MAP_DATA.MapList = malloc(MAPS_NUMBER * sizeof(i32*));
    GLOBAL.MAP_DATA.MapList[0] = (i32*)GAME_MAP1;
}

void game_set_CurrentMap(size_t mapID)
{
    if (mapID > MAPS_NUMBER - 1) 
    { ERROR_EXIT("Failed to load map ID: %d\n", (i32)mapID); }

    // Unload old map and load new map
    free_and_NULL(GLOBAL.GameState.CurrentMap);
    const size_t MapSizeBytes = sizeof(i32) * GLOBAL.MAP_DATA.WIDTH * GLOBAL.MAP_DATA.HEIGHT;
    i32 *MapCopy = malloc(MapSizeBytes);
    
    if (MapCopy == NULL) 
    { ERROR_EXIT("Failed to malloc MapCopy"); }

    memcpy(MapCopy, GLOBAL.MAP_DATA.MapList[mapID], MapSizeBytes);

    // Set Data
    GLOBAL.GameState.CurrentLevel = mapID;
    GLOBAL.GameState.CurrentMap = MapCopy;

    // Search for player in map data
    for (u32 w=0; w<GLOBAL.MAP_DATA.WIDTH; w++)
    {
        for (u32 h=0; h<GLOBAL.MAP_DATA.HEIGHT; h++)
        {
            if (MapCopy[h*GLOBAL.MAP_DATA.WIDTH + w] == TILE_PLAYER)
            {
                MapCopy[h*GLOBAL.MAP_DATA.WIDTH + w] == TILE_FLOOR;
                GLOBAL.GameState.PlayerPos = (vec2){w,h};
                break;
            }
        }
    }
    
}