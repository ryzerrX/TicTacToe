#include "board.h"

typedef struct Game 
{
  int gamerunning , current_player , stepcounter;
  Board *board;
}Game;

/// @brief initializes game
/// @param size 
/// @param streak 
/// @return game ptr
Game *init_game(int size,int streak);

/// @brief first destroys board and then the game
/// @param game 
void destroy_game(Game *game);

/// @brief main game loop
/// @param game 
void run_game(Game *game);