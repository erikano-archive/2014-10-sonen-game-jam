#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "cgame.h"
#include "slevel.h"
#include "splayer.h"

// Level 5, 3D, letter "T"
bool level5 (stats_level* stats_level5, player* player1, player* player2)
{
  fprintf(stderr, "Level not implemented.\n");
  (*stats_level5).error = EXIT_FAILURE;
  return false;
}
