#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "cgame.h"
#include "slevel.h"
#include "splayer.h"

// Level 1, text mode, letter "L"
bool level1 (stats_level* stats_level1, player* player1, player* player2)
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
    sleep(10);
    printf("\n            You die.");
    printf("\n");
    sleep(5);
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
    printf("\n\n      Your life force is sucked out.");
    printf("\n");
    sleep(10);
    (*player1).health = 0;
    printf("\n        You die.");
    printf("\n");
    sleep(5);
    (*stats_level1).error = EXIT_SUCCESS;
    return false;
  }
}
