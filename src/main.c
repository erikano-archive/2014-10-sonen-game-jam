#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "game.h"
#include "level.h"
#include "player.h"

int main (int argc, char* argv[])
{
  stats_level stats_level_current;
  player player1;
  player1.health = 100;

  player player2;
  player2.health = 100;

  bool made_it_through = level1(&stats_level_current, &player1, &player2);
  if (made_it_through && player1.health > 0 && player2.health > 0)
  {
    made_it_through = intro2(&stats_level_current, &player1, &player2);
  }
  if (made_it_through && player1.health > 0 && player2.health > 0)
  {
    made_it_through = level2(&stats_level_current, &player1, &player2);
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

  if (stats_level_current.error == EXIT_FAILURE)
  {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
