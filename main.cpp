/////////////////////////////
///
/// Matthew James Schmitz
///
/// December, 2016
///
/// File name: main.cpp
///
/////////////////////////////

#include <iostream>
#include <cmath>
#include <string>

#include "player.hpp"
#include "basketballfunctions.hpp"
#include "game state.hpp"

using namespace std;

const double OFF_REB_PCT = 0.132;
const double TO_PCT = 0.15;

Player players[5];

int passDestination;

int main()
{
    srand( time(NULL) );
    
    cout << "///////////////////////////////" << endl;
    cout << "//   Basketball Simulation   //" << endl;
    cout << "///////////////////////////////" << endl;
    cout << endl;
    cout << "In this game, you will be placed into a basketball game" << endl;
    cout << "in a close end-of-game situation, and you will be forced" << endl;
    cout << "to make decisions based on the score and the time remaining" << endl;
    cout << "in order to come out on top. You have five players on your" << endl;
    cout << "team, and their attributes are as follows:" << endl;
    cout << endl;
    cout << "Point guard:      2P%: 50%   3P%: 30%" << endl;
    cout << "Shooting guard:   2P%: 40%   3P%: 35%" << endl;
    cout << "Small Forward:    2P%: 45%   3P%: 25%" << endl;
    cout << "Power Forward:    2P%: 55%   3P%: 12%" << endl;
    cout << "Center:           2P%: 60%   3P%:  9%" << endl;
    cout << endl;
    cout << "Choose your passes wisely to avoid turnovers, and be mindful" << endl;
    cout << "of your shot selection to give yourself the best chances of" << endl;
    cout << "scoring and winning the basketball game." << endl;

    // Creating player objects
    players[0] = Player( "Point Guard", 0.500, 0.300 );
    players[1] = Player( "Shooting Guard", 0.400, 0.350 );
    players[2] = Player( "Small Forward", 0.450, 0.250 );
    players[3] = Player( "Power Forward", 0.550, 0.120 );
    players[4] = Player( "Center", 0.600, 0.090 );
    
    // Creating a game state object
    GameState Game;
    
    // Continue to play while the game clock has not expired
    while ( Game.gameClock > 0 )
    {
        // Give the player important game info
        cout << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << endl;
        Game.printGameInfo( players );
        cout << endl;
        cout << "/////////////////////////////////////////" << endl;
        cout << endl;
        
        // If you have possession then you get the option to shoot or pass
        // otherwise the opponent runs their possession
        if ( Game.possession == true )
        {
            option( Game, OFF_REB_PCT, TO_PCT, players, passDestination);
        }
        else
        {
            opponentPossession( Game, OFF_REB_PCT, TO_PCT );
        }
    }
    
    cout << endl;
    cout << endl;
    
    // Determining and displaying the winner after the game clock expires
    if ( Game.yourScore > Game.oppScore )
    {
        cout << "You won the game!" << endl;
        cout << "The final score was " << Game.yourScore << "-" << Game.oppScore << "." << endl;
    }
    else if ( Game.yourScore < Game.oppScore )
    {
        cout << "You lose the game." << endl;
        cout << "The final score was " << Game.yourScore << "-" << Game.oppScore << "." << endl;
    }
    else
    {
        cout << "The game ended in a tie." << endl;
        cout << "The final score was " << Game.yourScore << "-" << Game.oppScore << "." << endl;
    }
    
    cout << endl << endl;
    
    return 0;
}
