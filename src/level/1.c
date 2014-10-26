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
  int i;
  if (c == 'l')
  {
    printf("\n  As you open your eyes to look, from your left comes a terrible shriek;\n");
    printf("\n    NO! [L]EAVE!\n");
    sleep(1);
    printf("\n      Your eardrums shatter.\n");
    sleep(1);
    printf("\n        You fall to the ground.\n");
    sleep(1);
    printf("\n          You hit your head on a sharp object.\n");
    sleep(1);
    printf("\n            Still from your left, you hear a sobbing voice:\n");
    sleep(1);
    printf("\n              I didn't mean to...\n\n");
    sleep(1);
    fprintf(stderr, "                ");
    for (i = 0 ; i < 3 ; i++)
    {
      fprintf(stderr, ".");
      sleep(1);
    }
    (*player1).health = 0;
    printf("\n\n            You die.\n");
    sleep(1);
    fprintf(stderr, "\n              ");
    for (i = 0 ; i < 3 ; i++)
    {
      fprintf(stderr, ".");
      sleep(1);
    }
    printf("\n");
    sleep(1);
    (*stats_level1).error = EXIT_SUCCESS;
    return false;
  }
  else if (c == 'L')
  {
    printf("\n  You ignore the obviously malicious voice.\n");
    sleep(1);
    printf("\n    You leave this room.\n");
    sleep(1);
    printf("\n      Outside is nothing.\n");
    sleep(1);
    printf("\n        You leave this world\n");
    sleep(1);
    fprintf(stderr, "\n          ");
    for (i = 0 ; i < 3 ; i++)
    {
      fprintf(stderr, ".");
      sleep(1);
    }
    printf("\n\n          alive.\n");
    fprintf(stderr, "\n        ");
    for (i = 0 ; i < 3 ; i++)
    {
      fprintf(stderr, ".");
      sleep(1);
    }
    printf("\n");
    sleep(1);
    (*stats_level1).error = EXIT_SUCCESS;
    return true;
  }
  else
  {
    printf("\n  The voice now whips your ears:\n");
    printf("\n    MIND YOUR INPUT!\n");
    sleep(1);
    printf("\n      Your life force is sucked out.\n");
    sleep(1);
    fprintf(stderr, "\n        ");
    for (i = 0 ; i < 3 ; i++)
    {
      fprintf(stderr, ".");
      sleep(1);
    }
    (*player1).health = 0;
    printf("\n\n        You die.\n");
    sleep(1);
    fprintf(stderr, "\n          ");
    for (i = 0 ; i < 3 ; i++)
    {
      fprintf(stderr, ".");
      sleep(1);
    }
    printf("\n");
    sleep(1);
    (*stats_level1).error = EXIT_SUCCESS;
    return false;
  }
}
