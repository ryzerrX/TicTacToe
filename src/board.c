#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include "board.h"

void displayboard(Board *game_board)
{
    for (int i = 0; i < game_board->size; i++)
    {
        printf("\n");
        if (i != 0)
        {
            for (int x = 0; x < game_board->size; x++)
            {
                printf("-----------------");
            }
            printf("\n");
        }
        for (int j = 0; j < game_board->size; j++)
        {
            // switch (*(game_board->grid + (i * game_board->size) + j))
            switch (Get_Grid_Data(game_board,i,j))
            {
            case 1:
                printf("\tX\t");
                if (j != game_board->size - 1)
                {
                    printf("|");
                }
                break;
            case 2:
                printf("\tO\t");
                if (j != game_board->size - 1)
                {
                    printf("|");
                }
                break;

            default:
                printf("\t \t");
                if (j != game_board->size - 1)
                {
                    printf("|");
                }
                break;
            }
        }
    }
    printf("\n");
}

void inputposition(Board *game_board, int current_player)
{
    //    enter position
    //    scanf i & j
    //    store in arr[i][j]
    int input_not_registored = 1;
    int i, j, *seekptr;
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
        scanf("%d%d", &i, &j);

        if (i < game_board->size && i >= 0 && j < game_board->size && j >= 0)
        {
            seekptr = (game_board->grid + (i * game_board->size) + (j));
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

int checkboard(Board *game_board)
{   
    int i=0, j=0 ;
    bool win_found = false;
    
    for (i = 0; i < game_board->size; i++)
    {

        for (j = 0; j < game_board->size; j++)
        {
            // int temp=*(game_board->grid + (i * game_board->size) + (j));
            int temp = Get_Grid_Data(game_board,i,j);
            if (temp == 0)
            {
                continue;
            }
            
            if (i + (game_board->streak - 1)<game_board->size) //horizontal
            {
                for (int x = 1; x < game_board->streak; x++)
                {
                    win_found = true;
                    // if (*(game_board->grid + (i * game_board->size) + (j+x)) != temp) //identify position i & j in grid
                    if (Get_Grid_Data(game_board,i,j+x) != temp)
                    {
                        win_found = false;
                        break;
                    }
                    
                }
                if(win_found)
                {
                    return temp;
                }
            }
            if (j + (game_board->streak - 1)<game_board->size) //vertical
            {
                for (int x = 1; x < game_board->streak; x++)
                {
                    win_found = true;
                    // if (*(game_board->grid + ((i+x) * game_board->size) + (j)) != temp)
                    if(Get_Grid_Data(game_board,i+x,j) != temp)
                    {
                        win_found = false;
                        break;
                    }
                    
                }
                if(win_found)
                {
                    return temp;
                }
            }
            if (i + (game_board->streak-1)<game_board->size && j + (game_board->streak-1)<game_board->size)
            {
                for (int x = 1; x < game_board->streak; x++)
                {
                    win_found = true;
                    // if (*(game_board->grid + ((i+x) * game_board->size) + (j+x)) != temp)
                    if(Get_Grid_Data(game_board,i+x,j+x) != temp)
                    {
                        win_found = false;
                        break;
                    }
                    
                }
                if(win_found)
                {
                    return temp;
                }
            }
            if (j + (3-1)>game_board->size)
            {
                for (int x = 1; x < game_board->streak; x++)
                {
                    win_found = true;
                    // if (*(game_board->grid + ((i+x) * game_board->size) + (j-x)) != temp)
                    if(Get_Grid_Data(game_board,i+x,j-x) != temp)
                    {
                        win_found = false;
                        break;
                    }
                    
                }
                if(win_found)
                {
                    return temp;
                }
            }
        }
        
    }
    return 0;
}

Board *init_board(int size , int streak)
{
    if (size<streak)
    {
        return NULL;
    }
    
    Board *board;
    board= malloc(sizeof(Board));
    board->size = size;
    board->streak = streak;
    board->grid= malloc(sizeof(int)*size*size);
    return board;
}

void destroy_board(Board *board)
{
    if (board != NULL)
    {
        if (board->grid != NULL)
        {
            free(board->grid);
        }
        free(board);
    }
}
