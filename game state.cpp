/////////////////////////////
///
/// Matthew James Schmitz
///
/// December, 2016
///
/// File name: game state.cpp
///
/////////////////////////////

#include "player.hpp"
#include "game state.hpp"

// Setting game state variables
GameState::GameState()
{
    yourScore = rand() % ( 100 - 95 + 1) + 95; // Your score is set between 100 and 95
    oppScore = rand() % ( 110 - 100 + 1) + 100; // Opponent score is set between 100 and 110
    gameClock = rand() % ( 60 - 30 + 1) + 30; // Game clock is set between 30 and 60 seconds
    activePlayer = 1; // The point guard starts with the ball
    possession = true; // You start with possession
}

// Printing the game info
void GameState::printGameInfo( Player players[] )
{
    cout << "The score is " << yourScore << "-" << oppScore << "." << endl;
    
    if ( yourScore < oppScore )
    {
        cout << "You are down by " << oppScore - yourScore << " points." << endl;
    }
    else if ( yourScore > oppScore )
    {
        cout << "You are up by " << yourScore - oppScore << " points." << endl;
    }
    else
    {
        cout << "It is a tie game." << endl;
    }
    
    cout << "There are " << gameClock << " seconds left on the clock." << endl;
    
    if ( possession == true )
    {
        cout << "Your ";
        players[ activePlayer - 1 ].print_name();
        cout << " has the ball." << endl;
    }
    else
    {
        cout << "Your opponent has the ball." << endl;
    }
    
    return;
}
