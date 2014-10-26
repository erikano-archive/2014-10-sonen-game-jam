#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "cgame.h"
#include "slevel.h"
#include "splayer.h"
#include "flevel.h"

// So we can put the scenes (intros, levels, outros) in an array
bool (*scene[3]) (stats_level* stats_level_p, player* player1, player* player2);

int main (int argc, char* argv[])
{
  player player1;
  player1.health = 100;

  player player2;
  player2.health = 100;

  scene[0] = level1;
  scene[1] = intro2;
  scene[2] = level2;
  scene[3] = level3;
  scene[4] = level4;
  scene[5] = level5;
  scene[6] = outro5;

  int scene_curr;
  stats_level stats_level_curr;
  for (scene_curr = 0 ; scene_curr < 6 ; scene_curr++)
  {
    if (!(*scene[scene_curr])(&stats_level_curr, &player1, &player2))
    {
      if (stats_level_curr.error == EXIT_FAILURE)
      {
        return EXIT_FAILURE;
      }
      else
      {
        if (player1.health <= 0)
        {
          printf("\n  Dead people don't play games.\n");
          sleep(1);
          printf("\n    GAME OVER.");
        }
        else
        {
          printf("\n  You survived.\n");
          sleep(1);
          printf("\n    Mere survival is not sufficient.\n");
          sleep(1);
          printf("\n      GAME OVER.");
        }
        printf("\n\n");
        sleep(1);
        return EXIT_SUCCESS;
      }
    }
  }

  return EXIT_SUCCESS;
}
