// This file contains the function definitions for the League class 

#ifndef LEAGUE_HPP
#define LEAGUE_HPP

#include "League.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

// Default constructor - Not to be used
League::League() : divisions(2), num_teams(14), num_weeks(13) {
	teams.resize(14);
}

// Constructor with input
League::League(const int& divs, const int& n_teams, const int& n_weeks, const int& id, const int& idl, const std::vector<Player>& team_list, const std::map<int, std::string>& names_list) : divisions(divs), num_teams(n_teams), num_weeks(n_weeks), intra_divisional(id), intra_div_limit(idl), teams(team_list), names(names_list) { }

// Copy constructor
League::League(const League& input) : divisions(input.divisions), num_teams(input.num_teams), num_weeks(input.num_weeks), intra_divisional(input.intra_divisional), intra_div_limit(input.intra_div_limit), teams(input.teams), names(input.names) {}

// Destructor
League::~League(){}

// Assignment operator
League& League::operator = (const League& input){
	if (this == &input)
		return *this;

	divisions = input.divisions;
	num_teams = input.num_teams;
	num_weeks = input.num_weeks;
	intra_divisional = input.intra_divisional;
	intra_div_limit = input.intra_div_limit;
	teams = input.teams;
	names = input.names;
	return *this;
}

// Getter functions
int League::Divisions() const{	// Get the number of divisions
	return divisions;
}

int League::Num_Teams() const{	// Get the number of teams
	return num_teams;
}

int League::Num_Weeks() const{	// Get the number of weeks
	return num_weeks;
}

std::vector<Player> League::Teams() const{	// Get the list of teams
	return teams;
}

std::map<int, std::string> League::TeamNames() const{	//Get the team names
	return names;
}

std::vector<std::pair <int, int> > League::Week(const int& week_number) const{
	std::vector<std::pair<int, int> > week_list;
	for (int i = 0; i < num_teams; ++i){
		week_list.push_back(std::make_pair(i,teams[i].Matchups()[week_number]));
	}
	return week_list;
}

// Setter functions
void League::Divisions(const int& divs){	// Set the number of divisions
	divisions = divs;
}

void League::Num_Teams(const int& n_teams){	// Set the number of teams
	num_teams = n_teams;
	teams.resize(n_teams);
	std::cout << "The size of the vector holding the list of teams has been automatically resized." << std::endl;
}

void League::Num_Weeks(const int& n_weeks){	// Set the number of weeks
	num_weeks = n_weeks;
}

void League::Teams(const std::vector<Player>& team_list){	// Set the list of teams
	if (teams.size() == team_list.size())
		teams = team_list;
	else
		std::cout << "The vectors are not the same size." << std::endl;
}

void League::TeamNames(const std::map<int, std::string>& names_list){	// Set the names of the teams
	names = names_list;
}

void League::Week(const std::vector<std::pair<int, int> >& matchup_list, const int& week_number){
	for (std::vector<std::pair<int, int> >::const_iterator iter = matchup_list.begin(); iter != matchup_list.end(); ++iter){
		int team_num = iter->first;
		int matchup_num = iter->second;
		std::vector<int> temp_matchups = teams[team_num].Matchups();
		temp_matchups[week_number] = matchup_num;
		teams[team_num].Matchups(temp_matchups);
	}
}

// Function to generate the schedule
std::vector<std::vector<std::pair <int, int> > > League::GenerateSchedule(){
	std::vector<std::vector<std::pair <int, int> > > Schedule;
		// Create a random integer generator of numbers from 0 to the number of teams - 1
	boost::mt11213b rng(time(0));
	boost::uniform_int<> fourteen(0,num_teams - 1);
	boost::variate_generator<boost::mt11213b, boost::uniform_int<> > rand_val(rng,fourteen);

		// Create the vector of 40 random integers.  40 is an arbitrary number
	std::vector<int> RandNums;
	for (int i = 0; i < 40; ++i){
		RandNums.push_back(rand_val());
//			std::cout << RandNums[i] << std::endl;
	}

		// Instantiate Count and Limit matrices from the individual player counts and limits for tracking
	std::vector<std::vector<int> > Count_Matrix;
	std::vector<std::vector<int> > Limit_Matrix;
//		std::vector<int> ID_Vec;
//		std::vector<int> IDL_Vec;

		// Populate the Count and Limit Matrices
	for (int team_iter = 0; team_iter < num_teams; ++team_iter){
		Count_Matrix.push_back(teams[team_iter].Matchup_Count());
		Limit_Matrix.push_back(teams[team_iter].Matchup_Limit());
	}

	/***********************Main Loop************************/
	for (int week_val = 0; week_val < num_weeks; ++week_val){
		// Create the output vector that has pair elements
		std::vector<std::pair<int, int> > games(num_teams);

		// Create a boolean vector to track if a team already has a matchup this week and initialize all elements to false
		std::vector<bool> game_scheduled;
		for (int i = 0; i < num_teams; ++i)
			game_scheduled.push_back(false);

		// Main loop
		for (int i = 0; i < num_teams; ++i){
			// If the ith player does not already have a matchup scheduled
			if (game_scheduled[i] == false){
				// Run through the random number vector to find an opponent for the ith player
				for (std::vector<int>::const_iterator iter = RandNums.begin(); iter != RandNums.end(); ++iter){
					// If the opponent doesn't already have a game and the ith member is not the same as the "opponent" and check to see if the current count is under the limit
					if (game_scheduled[*iter] == false && i != *iter && Count_Matrix[i][*iter] < Limit_Matrix[i][*iter]){// && ((teams[i].Division() != teams[*iter].Division() && ID_Vec[i] < IDL_Vec[i]) || (teams[i].Division() == teams[*iter].Division()))){
						games[i] = std::make_pair(i,*iter);	// Create the pair for the ith member
						games[*iter] = std::make_pair(*iter,i);	// Create a corresponding pair for the opponent
						game_scheduled[i] = true;	// Set the game_scheduled value for the ith member equal to true
						game_scheduled[*iter] = true;	// Set the game_scheduled value for the "opponent" equal to true
						Count_Matrix[i][*iter]++;	// Increase the count by one
						Count_Matrix[*iter][i]++;	// Increase the opponent's count by one
						break;
					}
				}
			}
		}
		Schedule.push_back(games);
	}
	return Schedule;
}

// Function to print out the information as a string
std::string League::ToString() const{
	std::stringstream ss;
	ss << "Number of teams: " << num_teams << std::endl << "Number of weeks: " << num_weeks << std::endl << "Number of divisions: " << divisions << std::endl;
	ss << "Team List" << std::endl;
	for (std::map<int, std::string>::const_iterator iter = names.begin(); iter != names.end(); ++iter){
		ss << iter->second << std::endl;
	}
	return ss.str();
}

// Send to ostream
std::ostream& operator << (std::ostream& os, const League& input){
	os << input.ToString();
	return os;
}

#endif //! LEAGUE_HPP