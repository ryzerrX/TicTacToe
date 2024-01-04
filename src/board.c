#include <stdio.h>
#include "board.h"

void displayboard(board game_board)
{
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        if(i != 0)
        {
            printf("------------------------------------------------\n");
        }
        for (int j = 0; j < 3; j++)
        {
            switch (game_board.grid[i][j])
            {
            case 1:
                printf("\tX\t");
                if (j != 2)
                {
                    printf("|");
                }
                break;
            case 2:
                printf("\tO\t");
                if (j != 2)
                {
                    printf("|");
                }
                break;
            
            default:
                printf("\t \t");
                if (j != 2)
                {
                    printf("|");
                }
                break;
            }
            
        }
    }
    printf("\n");
    
}

void inputposition(board *game_board , int current_player)
{
//    enter position 
//    scanf i & j
//    store in arr[i][j]
    int input_not_registored = 1;
    int i , j , *seekptr;
    while (input_not_registored)
    {   
        if (current_player == 1)
        {
            printf("Enter position for 'X' [i][j]\n");
        }
        else
        {
            printf("Enter position for 'O' [i][j]\n");
        }
        scanf("%d%d",&i,&j);

        if(i<3 && i>=0 && j<3 && j>=0)
        {   
            seekptr = *game_board->grid + (i * 3) + (j );
            if (*seekptr == 0)
            {   
                *seekptr = current_player;
                input_not_registored = 0;
            }
            else
            {
                printf("Position Occupied, Enter diff position\n");
            }
        }
        else
        {
            printf("Enter [i][j] betn 0 to 2\n");
        }
    }
}

int checkboard(board game_board)
{
    for (int i = 0; i < 3; i++)
    {
        if (game_board.grid[i][0] == game_board.grid[i][1] && game_board.grid[i][0] == game_board.grid[i][2])
        {
            switch (game_board.grid[i][0])
            {
            case 1:
                printf("X wins\n");
                return 0;
            
            case 2:
                printf("O wins\n");
                return 0;
            default:
                break;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (game_board.grid[0][j] == game_board.grid[1][j] && game_board.grid[0][j] == game_board.grid[2][j])
        {
            switch (game_board.grid[0][j])
            {
            case 1:
                printf("X wins\n");
                return 0;
            
            case 2:
                printf("O wins\n");
                return 0;
            default:
                break;
            }
        }
    }
    if (game_board.grid[0][0] == game_board.grid[1][1] && game_board.grid[0][0] == game_board.grid[2][2] || game_board.grid[0][2] == game_board.grid[1][1] && game_board.grid[0][2] == game_board.grid[2][0])
    {
       switch (game_board.grid[1][1])
        {
            case 1:
                printf("X wins\n");
                return 0;
            
            case 2:
                printf("O wins\n");
                return 0;
            default:
                break;
        }
    }
    return 1;
}
