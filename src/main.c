/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main file of the project
 *
 *        Created:  03/24/2016 19:40:56
 *
 *         Author:  Gustavo Pantuza
 *   Organization:  Software Community
 *
 * ============================================================================
 */


#include <stdio.h>
#include "game.h"


void main()
{
    int size,streak;
    printf("Welcome to my TicTacToe Game\n");
    printf("Enter board size\n");
    scanf("%d",&size);
    printf("Enter board streak\n");
    scanf("%d",&streak);

    if (size<streak)
    {
        printf("Streak should be less than or equal to size of board. Therefore setting streak = %d\n",size);
    }
    Game *game;
    game=init_game(size,streak);
    run_game(game);
}


