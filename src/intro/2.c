#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "cgame.h"
#include "slevel.h"
#include "splayer.h"

bool intro2 (stats_level* stats_intro, player* player1, player* player2)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    (*stats_intro).error = EXIT_FAILURE;
    return false;
  }
  SDL_Window* window = SDL_CreateWindow("LIMIT -- Sonen Game Jam 2014, Team Erik", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    (*stats_intro).error = EXIT_FAILURE;
    return false;
  }
  SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
  SDL_UpdateWindowSurface(window);
  SDL_Delay(125);
  char i;
  for (i = 0; i < 255 ; i++)
  {
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, i, i, i));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5);
  }

  (*stats_intro).error = EXIT_SUCCESS;
  SDL_DestroyWindow(window);
  SDL_Quit();
  return true;
}
