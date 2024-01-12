#define Get_Grid_Data(game_board,i,j) (*(game_board->grid + (i * game_board->size) + (j)))
typedef struct Board
{
    int *grid;
    int size;
    int streak;
}Board;

/// @brief displays the game board
/// @param game_board 
void displayboard(Board *game_board);

/// @brief takes input position and sets player on that position
/// @param gameboard 
/// @param current_player 
void inputposition(Board *game_board , int player);

/// @brief checks for winner
/// @param game_board 
/// @return 
int checkboard(Board *game_board);

/// @brief initializes and returns pointer to board
/// @param size 
/// @param streak 
/// @return board pointer
Board *init_board(int size , int streak);

/// @brief destroys board
/// @param board 
void destroy_board(Board *board);