#include<stdlib.h>
#include<stdio.h>
#include "game.h"
#include "decideplayer.h"
Game *init_game(int size,int streak)
{
    Game *game;
    game=malloc(sizeof(Game));
    game->gamerunning=0; //false
    game->current_player=0;
    game->stepcounter=0;
    game->board=init_board(size,streak);
    return game;
}

void destroy_game(Game *game)
{
    if (game != NULL)
    {
        if (game->board != NULL)
        {
            destroy_board(game->board);
        }
        free(game);
    } 
}

void run_game(Game *game)
{
    game->gamerunning=1;
    displayboard(game->board);
    while (game->gamerunning)
    {
        game->current_player = decideplayer(game->stepcounter);
        inputposition(game->board , game->current_player);
        displayboard(game->board);
        game->stepcounter++;
        switch (checkboard(game->board))
        {
        case 1:
            printf("X is the Winner\n");
            game->gamerunning=0;
            break;
        case 2:
            printf("O is the Winner\n");
            game->gamerunning=0;
            break;

        default:
            break;
        }
        if (game->stepcounter == 9 && game->gamerunning)
        {
            printf("Its a Tie\n");
            game->gamerunning=0;
        }
    }
    destroy_game(game);
}

