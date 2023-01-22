#include "game_render.h"


void game_render_player(SDL_Renderer *renderer, const vec2 pos)
{
    SDL_Rect rect = {pos.x*GLOBAL.MAP_DATA.TILE_WIDTH, pos.y*GLOBAL.MAP_DATA.TILE_HEIGHT,
        GLOBAL.MAP_DATA.TILE_WIDTH, GLOBAL.MAP_DATA.TILE_HEIGHT};
    game_render_texture(renderer, NULL, &rect, "./img/player.png"); 
}


void game_render_tile(i32 tileID, SDL_Renderer *renderer, SDL_Rect *rect)
{
    switch (tileID)
    {
        case TILE_WALL:
        {
            game_render_texture(renderer, NULL, rect, "./img/wall.png"); 
            break;
        }
        case TILE_FLOOR:
        {
            break;
        }
        case TILE_BOULDER:
        {
            game_render_texture(renderer, NULL, rect, "./img/boulder.png"); 
            break;
        }
        case TILE_OBSTACLE:
        {
            game_render_texture(renderer, NULL, rect, "./img/obstacle.png"); 
            break;
        }
        case TILE_WIN:
        {
            game_render_texture(renderer, NULL, rect, "./img/win.png"); 
            break;
        }
    }
}


void game_render_map(SDL_Renderer *renderer, const i32 *mapToRender,
    const u32 mapWidth, const u32 mapHeight)
{
    for (u32 w=0; w<mapWidth; w++)
    {
        for (u32 h=0; h<mapHeight; h++)
        {
            SDL_Rect rect = {w*GLOBAL.MAP_DATA.TILE_WIDTH, h*GLOBAL.MAP_DATA.TILE_HEIGHT,
                GLOBAL.MAP_DATA.TILE_WIDTH, GLOBAL.MAP_DATA.TILE_HEIGHT};
            game_render_tile(mapToRender[(h*mapWidth + w)], renderer, &rect);
        }
    }
}


void game_render_texture(SDL_Renderer *renderer, const SDL_Rect *rectCrop, const SDL_Rect *rect,
    const char *imagePath)
{
    SDL_Surface *image = IMG_Load(imagePath);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    
    SDL_RenderCopy(renderer, texture, rectCrop, rect);

    SDL_FreeSurface(image);
    SDL_DestroyTexture(texture);
}


void game_render_win(SDL_Renderer *renderer)
{
    SDL_Surface *image = IMG_Load("./img/victory.png");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_Rect wholeScreen = {0,0,GLOBAL.WINDOW.WIDTH,GLOBAL.WINDOW.HEIGHT};
    
    SDL_RenderCopy(renderer, texture, NULL, &wholeScreen);

    SDL_FreeSurface(image);
    SDL_DestroyTexture(texture);
}