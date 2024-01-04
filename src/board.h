
typedef struct board
{
    int grid[3][3];
    int size;
    int streak;
}board;

/// @brief displays the game board
/// @param game_board 
void displayboard(board game_board);

/// @brief takes input position and sets player on that position
/// @param gameboard 
/// @param current_player 
void inputposition(board *game_board , int player);

/// @brief checks for winner
/// @param game_board 
/// @return 
int checkboard(board game_board);

