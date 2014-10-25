#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "cgame.h"
#include "slevel.h"
#include "splayer.h"

// Level 3, greyscale graphics and sound, letter "M"
bool level3 (stats_level* stats_level3, player* player1, player* player2)
{
  fprintf(stderr, "Level not implemented.\n");
  (*stats_level3).error = EXIT_FAILURE;
  return false;
}
