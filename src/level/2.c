#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "cgame.h"
#include "slevel.h"
#include "splayer.h"

// Level 2, black and white graphics, letter "I"
bool level2 (stats_level* stats_level2, player* player1, player* player2)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    (*player1).health = 0;
    (*stats_level2).error = EXIT_FAILURE;
    return false;
  }
  SDL_Window* window = SDL_CreateWindow("LIMIT -- Sonen Game Jam 2014, Team Erik", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    (*player1).health = 0;
    (*stats_level2).error = EXIT_FAILURE;
    return false;
  }
  SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

  // Load media
  SDL_Surface* sprite_player1 = SDL_LoadBMP("sprites/export/player1_bw.bmp");
  SDL_Surface* sprite_player2 = SDL_LoadBMP("sprites/export/player2_bw.bmp");
  if (sprite_player1 == NULL || sprite_player2 == NULL)
  {
    fprintf(stderr, "One or more sprites failed to load.\n");
    (*stats_level2).error = EXIT_FAILURE;
    return false;
  }

  // Game loop
  bool gameover = false;
  bool quit = false;
  SDL_Event e;
  while (!(gameover || quit))
  {
    // Event loop
    while(SDL_PollEvent(&e) != 0)
    {
      if(e.type == SDL_QUIT)
      {
        fprintf(stderr, "\n  User abort.");
        fprintf(stderr, "\n\n    GAME OVER.\n");
        (*stats_level2).error = EXIT_FAILURE;
        quit = true;
      }
    }
    SDL_BlitSurface(sprite_player1, NULL, screenSurface, NULL);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5000);
    gameover = true;
  }

  SDL_FreeSurface(sprite_player1);
  SDL_FreeSurface(sprite_player2);
  SDL_DestroyWindow(window);
  SDL_Quit();
  (*stats_level2).error = EXIT_SUCCESS;
  return true;
}
