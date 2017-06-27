/////////////////////////////
///
/// Matthew James Schmitz
///
/// December, 2016
///
/// File name: basketballfunctions.cpp
///
/////////////////////////////

#include "basketballfunctions.hpp"
#include "game state.hpp"
#include "player.hpp"

// Determines if you got the rebound or not
bool get_rebound( GameState &Game, const double ORP)
{
    Game.gameClock -= 1;
    
    Game.activePlayer = rand() % ( 5 - 1 + 1) + 1;
    
    if ( ((double) rand() / (RAND_MAX)) <= ORP )
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Allows you to choose who to pass to
void choose_pass_dest( int &PD)
{
    cout << "Who would you like to pass the ball to?" << endl;
    cout << " 1 = point guard" << endl;
    cout << " 2 = shooting guard" << endl;
    cout << " 3 = small forward" << endl;
    cout << " 4 = power forward" << endl;
    cout << " 5 = center" << endl;
    
    cin >> PD;
    
    // Ensuring a legitimate pass destination was indicated
    while ( PD < 1 || PD > 5 )
    {
        cout << "Please enter a valid pass destination using the following key:" << endl;
        cout << " 1 = point guard" << endl;
        cout << " 2 = shooting guard" << endl;
        cout << " 3 = small forward" << endl;
        cout << " 4 = power forward" << endl;
        cout << " 5 = center" << endl;
        
        cin >> PD;
    }
}

// Runs the opponents possession
void opponentPossession( GameState &Game, const double ORP, const double TOP )
{
    double determinationValue = ((double) rand() / (RAND_MAX));
    
    if ( determinationValue <= 0.200 ) // Turnover (20% chance)
    {
        Game.gameClock -= rand() % ( 6 - 1 + 1) + 1;
        
        Game.activePlayer = rand() % ( 5 - 1 + 1) + 1;
        
        Game.possession = true;
        
        cout << "The opponent turned the ball over before attempting a shot!" << endl;
    }
    else if ( determinationValue > 0.200 && determinationValue <= 0.500 ) // Take 3 (30% chance)
    {
        Game.gameClock -= rand() % ( 10 - 4 + 1) + 4;
        
        cout << "Your opponent attempted a 3 pointer." << endl;
        
        double didTheyScore = ((double) rand() / (RAND_MAX));
        
        if ( didTheyScore <= 0.300 ) // They do score
        {
            Game.possession = true;
            
            Game.oppScore += 3;
            
            cout << "Your opponent scored." << endl;
        }
        else // Don't score
        {
            cout << "Your opponent missed." << endl;
            
            if ( get_rebound( Game, ORP ) )
            {
                cout << "Your opponent got the offensive rebound." << endl;
            }
            else
            {
                cout << "You got the defensive rebound." << endl;
                Game.possession = true;
            }
        }
    }
    else // Take 2 (50% chance)
    {
        Game.gameClock -= rand() % ( 10 - 3 + 1) + 3;
        
        cout << "Your opponent attempted a 2 pointer." << endl;
        
        double didTheyScore = ((double) rand() / (RAND_MAX));
        
        if ( didTheyScore <= 0.450 ) // They do score
        {
            Game.possession = true;
            
            Game.oppScore += 2;
            
            cout << "Your opponent scored." << endl;
        }
        else // Don't score
        {
            cout << "Your opponent did not score." << endl;
            
            if ( get_rebound( Game, ORP ) )
            {
                cout << "Your opponent got the offensive rebound." << endl;
            }
            else
            {
                cout << "You got the defensive rebound." << endl;
                Game.possession = true;
            }
        }
    }
    
    return;
}

// Gives you the option to pass or shoot
void option( GameState &Game, const double ORP, const double TOP, Player players[], int PD )
{
    int shootOrPass;
    
    cout << "Would you like to shoot the ball or pass the ball?" << endl;
    cout << "Indicate with shoot = 1, pass = 2." << endl;
    
    cin >> shootOrPass;
    
    cout << endl << endl;
    
    while ( shootOrPass != 1 && shootOrPass != 2 )
    {
        cout << "Please select a valid option from shoot = 1, pass = 2." << endl;
        
        cin >> shootOrPass;
        
        cout << endl << endl;
    }
    
    switch ( shootOrPass )
    {
        case 1:
            players[ Game.activePlayer - 1 ].shoot( Game, ORP );
            break;
            
        case 2:
            players[ Game.activePlayer - 1 ].pass( PD, players, TOP, Game );
            break;
    }
    
    cout << endl << endl;
}







