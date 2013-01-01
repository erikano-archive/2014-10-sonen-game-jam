#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main (int argc, char* argv[])
{
  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  window = SDL_CreateWindow("LIMIT -- Sonen Game Jam 2014, Team Erik", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  screenSurface = SDL_GetWindowSurface(window);

  // Intro
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
        quit = true;
      }
    }
    SDL_Delay(5);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  if (gameover)
  {
    fprintf(stderr, "Game over.\n");
    return EXIT_SUCCESS;
  }

  fprintf(stderr, "User abort.\n");
  return EXIT_FAILURE;
}
