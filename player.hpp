/////////////////////////////
///
/// Matthew James Schmitz
///
/// December, 2016
///
/// File name: player.hpp
///
/////////////////////////////

#ifndef player_hpp
#define player_hpp

#include "includes.h"

#include <stdio.h>
#include <string>

using namespace std;

class GameState;

class Player
{
public:
    Player(); // Default constructor
    Player( string name, double TPP, double ThPP ); // Overloaded constructor
    double get_two_point_pct(); // returns two pt pct
    double get_three_point_pct(); // returns three pt pct
    void print_name(); // prints the name of the player
    void shoot( GameState &Game, const double ORP ); // Runs when the user opts to shoot the ball
    void pass( int PD, Player players[], const double TO_PCT, GameState &Game ); // Runs when the user opts to pass the ball
    bool score2( GameState &Game, const double ORP ); // Determines if a player scores when shooting a two pointer
    bool score3( GameState &Game, const double ORP ); // Determines if a player scores when shooting a three pointer
private:
    double three_point_pct; // Player's three point percentage
    double two_point_pct; // Player's two point percentage
    string name; // Player's name
};

#endif /* player_hpp */
