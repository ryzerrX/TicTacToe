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

int checkboard(int gameboard[3][3]) 
{   
    int i=0,j=0,val;
    bool match = true;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
           if(gameboard[i][j] != gameboard[i][j+1])
           {
                break;
           }
        }
        if (j == 2)
        {
            switch (gameboard[i][j])
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
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
           if(gameboard[i][j] != gameboard[i+1][j])
           {
                break;
           }
        }
        if (i == 2)
        {
            switch (gameboard[i][j])
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
    val = gameboard[i][j];
    while(i < 3 && match)
    {
        
        if (gameboard[i][j] != val)
        {
            match = false;
        }
        i++;
        j++;
        
    }
    if (gameboard[i][j] == val)
        {
            switch (gameboard[i][j])
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
