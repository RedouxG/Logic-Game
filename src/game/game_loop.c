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
    if (keysPressed[SDL_SCANCODE_A]) { game_move_player((vec2){-1,0}); }
    if (keysPressed[SDL_SCANCODE_W]) { game_move_player((vec2){0,-1}); }
    if (keysPressed[SDL_SCANCODE_S]) { game_move_player((vec2){0,1});  }
    if (keysPressed[SDL_SCANCODE_D]) { game_move_player((vec2){1,0});  }
}


void start_game_loop()
{
    init_game_data();

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    { ERROR_EXIT("Unable to init SDL2 %s\n", SDL_GetError()); }

    if(!IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG)
    { ERROR_EXIT("Unable to init SDL2_image %s\n", IMG_GetError()); }

    SDL_Window *window = init_window();
    SDL_Renderer *renderer = init_renderer(window);

    game_set_CurrentMap(0);

    // Game loop
    SDL_Event event;
    bool shouldQuit = false;
    while(!shouldQuit)
    {
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
        game_render_map(renderer, GLOBAL.GameState.CurrentMap, GLOBAL.MAP_DATA.WIDTH, GLOBAL.MAP_DATA.HEIGHT);
        game_render_player(renderer, GLOBAL.GameState.PlayerPos);

        // Draw render
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
}