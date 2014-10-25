#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

typedef struct player_ {
  int health;
} player;

typedef struct stats_level_ {
  int error;
} stats_level;

// "L" -- text mode
int level1 (SDL_Window* window, SDL_Surface* screenSurface, stats_level* stats_level1, player* player1, player* player2)
{
  printf("\n  You are standing in a room.");
  printf("\n\n  A sly, female voice speaks in front of you:");
  printf("\n\n    The limit of what you can do is:");
  printf("\n\n      [l]ook.");
  printf("\n\n  What do you do?");
  printf("\n\n    : ");
  char c = getchar();
  if (c == 'l')
  {
    printf("\n  As you open your eyes to look, from your left comes a terrible shriek;");
    printf("\n\n    NO! [L]EAVE!");
    printf("\n\n      Your eardrums shatter.");
    printf("\n\n        You fall to the ground.");
    printf("\n\n          You hit your head on a sharp object.");
    printf("\n\n            Still from your left, you hear a sobbing voice:");
    printf("\n\n              I didn't mean to...");
    printf("\n");
    (*player1).health = 0;
    sleep(15);
    printf("\n            You die.");
    printf("\n");
    (*stats_level1).error = EXIT_SUCCESS;
    return false;
  }
  else if (c == 'L')
  {
    printf("\n  You ignore the obviously malicious voice.");
    printf("\n\n    You leave this room.");
    printf("\n\n      Outside is nothing.");
    printf("\n\n        You leave this world");
    printf("\n");
    sleep(10);
    printf("\n          alive.");
    printf("\n");
    sleep(5);
    (*stats_level1).error = EXIT_SUCCESS;
    return true;
  }
  else
  {
    printf("\n  The voice now whips your ears:");
    printf("\n\n    MIND YOUR INPUT!");
    printf("\n");
    sleep(15);
    (*player1).health = 0;
    printf("\n      Your life force is sucked out.");
    printf("\n\n        You die.");
    printf("\n");
    (*stats_level1).error = EXIT_SUCCESS;
    return false;
  }
}

int intro (SDL_Window* window, SDL_Surface* screenSurface, stats_level* stats_intro, player* player1, player* player2)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    (*player1).health = 0;
    (*stats_intro).error = EXIT_FAILURE;
    return false;
  }

  window = SDL_CreateWindow("LIMIT -- Sonen Game Jam 2014, Team Erik", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    (*player1).health = 0;
    (*stats_intro).error = EXIT_FAILURE;
    return false;
  }

  screenSurface = SDL_GetWindowSurface(window);

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
  return true;
}

// "I" -- black and white

// "M" - greyscale and sound

// "I" - colors

// "T" - 3D

/* After "L-I-M-I-T" has been collected, the good one appears.
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
 * (Play a *deep* note)
 *
 * "THE END"
 */

int main (int argc, char* argv[])
{
  stats_level stats_level_current;
  player player1;
  player1.health = 100;

  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;

  player player2;
  player2.health = 100;

  bool made_it_through = level1(window, screenSurface, &stats_level_current, &player1, &player2);
  if (made_it_through && player1.health > 0 && player2.health > 0)
  {
    made_it_through = intro(window, screenSurface, &stats_level_current, &player1, &player2);
  }
  if (made_it_through && player1.health > 0 && player2.health > 0)
  {
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
          stats_level_current.error = EXIT_FAILURE;
          quit = true;
        }
      }
      SDL_Delay(5);
    }
  }
  if (stats_level_current.error != EXIT_FAILURE)
  {
    if (player1.health <= 0)
    {
      printf("\n  Dead people don't play games.");
      printf("\n\n    GAME OVER.");
    }
    else
    {
      printf("\n  You survived.");
      printf("\n\n    Mere survival is not sufficient.");
      printf("\n\n      GAME OVER.");
    }
    printf("\n\n");
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  if (stats_level_current.error == EXIT_FAILURE)
  {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
