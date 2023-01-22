#include "game_logic.h"


void game_set_tile_at(i32 tileID, vec2 pos)
{
    i32 index = pos.y*GLOBAL.MAP_DATA.WIDTH + pos.x;
    if (index < 0 || index > (GLOBAL.MAP_DATA.HEIGHT*GLOBAL.MAP_DATA.WIDTH))
    { ERROR_MSG("Tried to set tile on index over CurrentMap bounds: %d", index); return; }
    GLOBAL.GameState.CurrentMap[index] = tileID;
}


i32 game_get_tile_at(vec2 pos)
{
    i32 index = pos.y*GLOBAL.MAP_DATA.WIDTH + pos.x;
    if (index < 0 || index > (GLOBAL.MAP_DATA.HEIGHT*GLOBAL.MAP_DATA.WIDTH))
    { ERROR_MSG("Tried to get tile on index over CurrentMap bounds: %d", index); return -1; }
    return GLOBAL.GameState.CurrentMap[index];
}


void game_move_player(vec2 direction)
{
    i32 xAfter = GLOBAL.GameState.PlayerPos.x + direction.x;
    i32 yAfter = GLOBAL.GameState.PlayerPos.y + direction.y;

    // Check map bounds
    if (xAfter < 0) { return; }
    if (yAfter < 0) { return; }
    if (xAfter > GLOBAL.MAP_DATA.WIDTH-1) { return; }
    if (yAfter > GLOBAL.MAP_DATA.WIDTH-1) { return; }

    i32 tileID = game_get_tile_at((vec2){xAfter, yAfter});
    switch (tileID)
    {
        case TILE_WALL: { return; }
        case TILE_BOULDER: 
        { 
            vec2 fromPos = {xAfter, yAfter};
            vec2 toPos = {xAfter + direction.x, yAfter + direction.y};
            if (!(game_move_boulder(fromPos, toPos))) { return; }
            break;
        }
        case TILE_WIN:
        { 
            game_win(); 
            return; 
        }
        case TILE_OBSTACLE:
        { 
            game_restart_level(); 
            return; 
        }
    }

    GLOBAL.GameState.PlayerPos.x = xAfter;
    GLOBAL.GameState.PlayerPos.y = yAfter;
}


bool game_move_boulder(vec2 fromPos, vec2 toPos)
{
    if(!(game_get_tile_at(toPos) == TILE_FLOOR)) { return false; }
    game_set_tile_at(TILE_FLOOR, fromPos);
    game_set_tile_at(TILE_BOULDER, toPos);
    return true;
}


void game_win()
{
    u32 nextLevel = GLOBAL.GameState.CurrentLevel + 1;
    if (nextLevel >= GLOBAL.MAP_DATA.MapsNumber)
    {
        GLOBAL.GameState.Won = true;
        return;
    }
    GLOBAL.GameState.CurrentLevel = nextLevel;
    game_load_map(GLOBAL.GameState.CurrentLevel);
}

void game_restart_level()
{
    game_load_map(GLOBAL.GameState.CurrentLevel);
}