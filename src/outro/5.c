#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "cgame.h"
#include "slevel.h"
#include "splayer.h"

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
bool outro5 (stats_level* stats_outro5, player* player1, player* player2)
{
  fprintf(stderr, "Outro not implemented.\n");
  (*stats_outro5).error = EXIT_FAILURE;
  return false;
}
