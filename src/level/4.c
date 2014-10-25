#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "cgame.h"
#include "slevel.h"
#include "splayer.h"

// Level 4, color graphics, letter "I"
bool level4 (stats_level* stats_level4, player* player1, player* player2)
{
  fprintf(stderr, "Level not implemented.\n");
  (*stats_level4).error = EXIT_FAILURE;
  return false;
}
