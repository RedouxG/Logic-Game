#include "global_data.h"


_global GLOBAL = {
    .WINDOW = {
        .NAME = "Simple Logic Game",
        .WIDTH = 576, 
        .HEIGHT = 576,
    },
    .MAP_DATA = {
        .HEIGHT = 9,
        .WIDTH = 9,
        .TILE_HEIGHT = 64,
        .TILE_WIDTH = 64,
        .MapsNumber = 0,
    },
    .GameState = {
        .CurrentLevel = 0,
        .CurrentMap = NULL,
        .Won = false,
    },
    .DelayFrames = 0,
    .FRAME_DELAY = 10,
};


u32 count_levels_in_dir()
{
    u32 fileCount = 0;
    char FileName[256];

    while(true)
    {
        sprintf(FileName,".\\levels\\%u.txt", fileCount);
        FILE *file = fopen(FileName, "r");
        if (!file) { break; }
        fileCount++;
    }

    return fileCount;
}


bool game_load_map(u32 level)
{
    char FileName[256];
    sprintf(FileName,".\\levels\\%u.txt",level);

    FILE *file = fopen(FileName, "r");
    if (!file)
    { ERROR_MSG("Unable to load file: %s", FileName); return false; }

    const size_t MapSizeBytes = sizeof(i32) * GLOBAL.MAP_DATA.WIDTH * GLOBAL.MAP_DATA.HEIGHT;
    i32 *NewMap = malloc(MapSizeBytes);
    if (NewMap == NULL) 
    { ERROR_MSG("Failed to malloc NewMap"); return false; }

    char ch = ' ';
    u32 index = 0;
    while (ch != EOF)
    {
        ch = fgetc(file);
        if( !(ch >= '0' && ch <= '9') ) { continue; }

        u32 tileID;
        sscanf(&ch, "%u", &tileID);
        NewMap[index] = tileID;

        index++;
        if (index >= MapSizeBytes) { break; }
    }

    GLOBAL.GameState.CurrentLevel = level;      // Assign level number
    free_and_NULL(GLOBAL.GameState.CurrentMap); // Get rid of old map
    GLOBAL.GameState.CurrentMap = NewMap;       // Assign new map

    // Search for player and win in map data
    for (i32 w=0; w<GLOBAL.MAP_DATA.WIDTH; w++)
    {
        for (i32 h=0; h<GLOBAL.MAP_DATA.HEIGHT; h++)
        {
            if (NewMap[h*GLOBAL.MAP_DATA.WIDTH + w] == TILE_PLAYER)
            {
                NewMap[h*GLOBAL.MAP_DATA.WIDTH + w] = TILE_FLOOR;
                GLOBAL.GameState.PlayerPos = (vec2){w,h};
            }
            else if (NewMap[h*GLOBAL.MAP_DATA.WIDTH + w] == TILE_WIN)
            {
                GLOBAL.GameState.WinPos = (vec2){w,h};
            }
        }
    }
    return true;
}