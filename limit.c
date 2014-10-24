#include <stdio.h>
#include <stdbool.h>

typedef struct player_ {
  int health;
} player;

int level1 (player* player1)
{
  printf("\n  You are standing in a room.");
  printf("\n\n  A sly, female voice speaks in front of you:");
  printf("\n\n    The LIMIT of what you can do is:");
  printf("\n\n      [l]ook.");
  printf("\n\n  What do you do?");
  printf("\n\n      : ");
  char c = getchar();
  if (c == 'l')
  {
    printf("\n  As you open your eyes to look, from your left comes a terrible shriek;");
    printf("\n\n    NO! [L]EAVE!");
    printf("\n\n      Your eardrums shatter.");
    printf("\n\n        You fall to the ground.");
    printf("\n\n          You hit your head on a sharp object.");
    printf("\n\n            The last thing you hear is a sobbing voice:");
    printf("\n\n              I didn't mean to...");
    (*player1).health = 0;
    printf("\n\n            You die.");
    return false;
  }
  else if (c == 'L')
  {
    printf("\n  Not listening to the obviously malicious voice, you leave this room.");
    printf("\n\n    Outside is nothing.");
    printf("\n\n      You *L*eave this world.");
    return false;
  }
  else
  {
    printf("\n  The voice now whips you:");
    printf("\n\n    MIND YOUR INPUT!");
    (*player1).health = 0;
    printf("\n\n  Your life force is sucked out.");
    return false;
  }
}

#include <SDL2/SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// ...

/* After "L-I-M-I-T" has been collected, the good one speaks:
 *
 *   You were able to see through the lies of the evil.
 *
 * One after another, she gently picks up the letters.
 *
 * She floats them in the air and forms them to the word.
 *
 * She looks at you.
 *
 * With a wave of her hand, the letters disappear.
 *
 * Fade to black
 *
 * (Play a deep note)
 *
 * "THE END"
 */

int main (int argc, char* argv[])
{
  player player1;
  player1.health = 100;
  player player2;
  player2.health = 100;

  bool made_it_through = true;
  while (made_it_through && player1.health > 0)
  {
    made_it_through = level1(&player1);
  }

  if (player1.health <= 0)
  {
    printf("\n\n  Dead people don't play games.");
    printf("\n\n    GAME OVER.");
  }
  else
  {
    printf("\n\n  You survived.");
    printf("\n\n    Mere survival is not sufficient.");
    printf("\n\n      GAME OVER.");
  }
  printf("\n\n");

  /*
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
  */
}
