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
#include "board.h"
#include "decideplayer.h"

void main()
{
    board game_board;
    int gamerunning = 1 , current_player;
    stepcounter = 0;
    while (gamerunning)
    {
        current_player = decideplayer(stepcounter);
        inputposition(&game_board , current_player);
        displayboard(game_board);
        gamerunning=checkboard(game_board);
        stepcounter++;
        if (stepcounter == 9 && gamerunning)
        {
            printf("Its a Tie");
            gamerunning=0;
        }
        
    }
}


