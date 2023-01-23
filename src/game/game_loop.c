#include "game_loop.h"


SDL_Window* init_window()
{
    SDL_Window *window = SDL_CreateWindow(GLOBAL.WINDOW.NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
         GLOBAL.WINDOW.WIDTH, GLOBAL.WINDOW.HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == window)
    { ERROR_EXIT("Unable to create window %s\n", SDL_GetError()); }
    return window;
}


SDL_Renderer* init_renderer(SDL_Window *window)
{
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 
            SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if (NULL == renderer)
    { ERROR_EXIT("Unable to create renderer %s\n", SDL_GetError()); }
    return renderer;
}


void handle_key_event(const u8* keysPressed)
{
    if (GLOBAL.DelayFrames>0) { return; }
    else if (keysPressed[SDL_SCANCODE_A]) { game_move_player((vec2){-1,0}); } // Move left
    else if (keysPressed[SDL_SCANCODE_W]) { game_move_player((vec2){0,-1}); } // Move up
    else if (keysPressed[SDL_SCANCODE_S]) { game_move_player((vec2){0,1});  } // Move down
    else if (keysPressed[SDL_SCANCODE_D]) { game_move_player((vec2){1,0});  } // Move right
    else if (keysPressed[SDL_SCANCODE_R]) { game_restart_level(); } // Restart level
    else { return; } // No action

    GLOBAL.DelayFrames = GLOBAL.FRAME_DELAY;
}


void start_game_loop()
{
    GLOBAL.MAP_DATA.MapsNumber = count_levels_in_dir();
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    { ERROR_EXIT("Unable to init SDL2 %s\n", SDL_GetError()); }

    if(!IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG)
    { ERROR_EXIT("Unable to init SDL2_image %s\n", IMG_GetError()); }

    SDL_Window *window = init_window();
    SDL_Renderer *renderer = init_renderer(window);

    game_load_map(10);

    // Game loop
    SDL_Event event;
    bool shouldQuit = false;
    while(!shouldQuit)
    {
        if (GLOBAL.DelayFrames>0) { GLOBAL.DelayFrames--; }
        // Event handling
        while (SDL_PollEvent(&event)) 
        { 
            switch (event.type)
            {
                case SDL_QUIT:    { shouldQuit = true; break; }
                case SDL_KEYDOWN: { handle_key_event(SDL_GetKeyboardState(NULL)); }
                default: break;
            }
        }

        // Clear render
        SDL_RenderClear(renderer);
            
        // Update render
        if (!GLOBAL.GameState.Won)
        {
            game_render_map(renderer, GLOBAL.GameState.CurrentMap, GLOBAL.MAP_DATA.WIDTH, GLOBAL.MAP_DATA.HEIGHT);
            game_render_player(renderer, GLOBAL.GameState.PlayerPos);
        } else
        { game_render_win(renderer); }

        // Draw render
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
}