/////////////////////////////
///
/// Matthew James Schmitz
///
/// December, 2016
///
/// File name: game state.hpp
///
/////////////////////////////

#ifndef game_state_hpp
#define game_state_hpp

#include "includes.h"

#include <stdio.h>

using namespace std;

class Player;

class GameState
{
public:
    GameState(); // Constructor
    void printGameInfo( Player players[] ); // Prints out the game info
    int yourScore; // Your score
    int oppScore; // Opponent score
    int gameClock; // Time in seconds remaining on the game clock
    bool possession; // Whether or not you have possession
    int activePlayer; // Which player on your team actively has the ball
};

#endif /* game_state_hpp */
