/////////////////////////////
///
/// Matthew James Schmitz
///
/// December, 2016
///
/// File name: basketballfunctions.hpp
///
/////////////////////////////

#ifndef basketball_functions_hpp
#define basketball_functions_hpp

#include "includes.h"

#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std;

class Player;
class GameState;

bool get_rebound( GameState &Game, const double ORP ); // Determines if you got the rebound or not

void choose_pass_dest( int &PD ); // Allows you to choose the player you want to pass to

void option( GameState &Game, const double ORP, const double TOP, Player players[], int PD ); // Gives you the option to pass or shoot

void opponentPossession( GameState &Game, const double ORP, const double TOP ); // Runs the opponents possession

#endif /* basketball_functions_hpp */
