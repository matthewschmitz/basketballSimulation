/////////////////////////////
///
/// Matthew James Schmitz
///
/// December, 2016
///
/// File name: player.cpp
///
/////////////////////////////

#include "player.hpp"
#include "game state.hpp"
#include "basketballfunctions.hpp"

// Default constructor
Player::Player()
{
    name = "Player";
    two_point_pct = 0.450;
    three_point_pct = 0.330;
}

// Constructor to set values or variables
Player::Player( string name, double TPP, double ThPP ) : name(name), two_point_pct(TPP), three_point_pct(ThPP)
{
}

// returns two pt pct
double Player::get_two_point_pct()
{
    return two_point_pct;
}

// returns three pt pct
double Player::get_three_point_pct()
{
    return three_point_pct;
}

// prints the player's name
void Player::print_name()
{
    cout << name;
    return;
}

// Runs when the user opts to shoot the ball
void Player::shoot( GameState &Game, const double ORP )
{
    int shotSelection;
    
    cout << "Would you like to shoot a 2 pointer or a 3 pointer?" << endl;
    cout << "Please indicate '2' or '3'" << endl;
    
    cin >> shotSelection;
    
    while ( shotSelection != 2 && shotSelection != 3 )
    {
        cout << "Please select a valid shot type (2 or 3)." << endl;
        cout << "Would you like to shoot a 2 pointer or a 3 pointer?" << endl;
        
        cin >> shotSelection;
    }
    
    switch ( shotSelection )
    {
        case 2:
            score2( Game, ORP );
            break;
            
        case 3:
            score3( Game, ORP );
            break;
    }
    
    return;
}

// Determines if a player scores or not when shooting a two pointer
bool Player::score2( GameState &Game, const double ORP )
{
    Game.gameClock -= 3;
    
    if ( ((double) rand() / (RAND_MAX)) <= two_point_pct )
    {
        Game.yourScore += 2;
        Game.possession = false;
        cout << "You scored! Your team now has " << Game.yourScore << " points." << endl;
        cout << "The other team now has possession." << endl;
    }
    else
    {
        cout << "You did not score." << endl;
        
        if ( get_rebound( Game, ORP ) )
        {
            cout << "You got the offensive rebound." << endl;
        }
        else
        {
            cout << "The other team got the defensive rebound." << endl;
            Game.possession = false;
        }
    }
    
    return Game.possession;
}

// Determines if a player scores or not when shooting a three pointer
bool Player::score3( GameState &Game, const double ORP )
{
    Game.gameClock -= 4;
    
    if ( ((double) rand() / (RAND_MAX)) <= three_point_pct )
    {
        Game.yourScore += 3;
        Game.possession = false;
        cout << "You scored! Your team now has " << Game.yourScore << " points." << endl;
        cout << "The other team now has possession." << endl;
    }
    else
    {
        cout << "You did not score." << endl;
        
        if ( get_rebound( Game, ORP ) )
        {
            cout << "You got the offensive rebound." << endl;
        }
        else
        {
            cout << "The other team got the defensive rebound." << endl;
            Game.possession = false;
        }
    }
    
    return Game.possession;
}

// Runs when the user opts to pass the basketball
void Player::pass( int PD, Player players[], const double TO_PCT, GameState &Game )
{
    Game.gameClock -= 2;
    
    choose_pass_dest( PD );
    
    if ( PD == Game.activePlayer )
    {
        players[ PD - 1 ].print_name();
        cout << " already has the ball." << endl;
    }
    else if ( ((double) rand() / (RAND_MAX)) > TO_PCT )
    {
        cout << "The pass made it through." << endl;
        
        Game.activePlayer = PD;
        
        cout << "Your ";
        players[ PD - 1 ].print_name();
        cout << " now has the ball." << endl;
    }
    else
    {
        cout << "You turned the ball over." << endl;
        
        Game.possession = false;
    }
    
    return;
}



