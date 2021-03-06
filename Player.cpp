// This file contains all of the function definitions for the Player class

#include "Player.hpp"
#include <iostream>
#include <sstream>

// Default constructor - Not to be used
Player::Player() : num_weeks(13), num_teams(14), division(1), place(0), intra_divisional(0), intra_div_limit(2), name("Generic Team Name") {
	matchups.resize(num_weeks);
	matchup_limit.resize(num_teams);
	matchup_count.resize(num_teams);
	for(int i = 0; i < 14; ++i){
		if (i < 7)
			matchup_limit[i] = 2;
		else
			matchup_limit[i] = 1;
	}
	matchup_limit[0] = 0;
}

// Constructor with input
Player::Player(const std::vector<int>& limit, const std::vector<int>& count, const int weeks, const int teams, const int div, const int rank, const int id, const int idl, const std::string team_name) : matchup_limit(limit), matchup_count(count), num_weeks(weeks), num_teams(teams), division(div), place(rank), intra_divisional(id), intra_div_limit(idl), name(team_name) {
	matchups.resize(weeks);
}

// Copy constructor
Player::Player(const Player& input): matchups(input.matchups), matchup_limit(input.matchup_limit), matchup_count(input.matchup_count), num_weeks(input.num_weeks), num_teams(input.num_teams), division(input.division), place(input.place), intra_divisional(input.intra_divisional), intra_div_limit(input.intra_div_limit), name(input.name) { }

// Destructor
Player::~Player(){ }

// Assignment operator
Player& Player::operator = (const Player& input){
	if (this == &input)
		return *this;

	matchups = input.matchups;
	matchup_limit = input.matchup_limit;
	matchup_count = input.matchup_count;
	num_weeks = input.num_weeks;
	num_teams = input.num_teams;
	division = input.division;
	place = input.place;
	name = input.name;
	intra_divisional = input.intra_divisional;
	intra_div_limit = input.intra_div_limit;
	return *this;
}

// Getter functions
std::vector<int> Player::Matchups() const {
	return matchups;
}

std::vector<int> Player::Matchup_Count() const{
	return matchup_count;
}

std::vector<int> Player::Matchup_Limit() const{
	return matchup_limit;
}

int Player::Division() const{
	return division;
}

int Player::Place() const{
	return place;
}

int Player::Num_Weeks() const{
	return num_weeks;
}

int Player::Num_Teams() const{
	return num_teams;
}

int Player::Intra_Div() const{
	return intra_divisional;
}

int Player::Intra_Div_Limit() const{
	return intra_div_limit;
}

std::string Player::Name() const{
	return name;
}

// Setter functions
void Player::Matchups(const std::vector<int>& input){
	if (matchups.size() == input.size())
		matchups = input;
	else{
		std::cout << "The vectors are not the same size." << std::endl;
	}
}

void Player::Matchup_Count(const std::vector<int>& input){
	if (matchup_count.size() == input.size())
		matchup_count = input;
	else{
		std::cout << "The vectors are not the same size." << std::endl;
	}
}

void Player::Matchup_Limit(const std::vector<int>& input){
	if (matchup_limit.size() == input.size())
		matchup_limit = input;
	else{
		std::cout << "The vectors are not the same size." << std::endl;
	}
}

void Player::Division(const int& input){
	division = input;
}

void Player::Place(const int& rank){
	place = rank;
}

void Player::Intra_Div(const int& id){
	intra_divisional = id;
}

void Player::Intra_Div_Limit(const int& idl){
	intra_div_limit = idl;
}

void Player::Name(const std::string& team_name){
	name = team_name;
}

// Function to print out the information as a string
std::string Player::ToString() const{
	std::stringstream ss;
	ss << "Team: " << name << ", Division: " << division << ".  Matchups: " << std::endl;
	for (int i = 0;i < num_weeks; ++i){
		ss << "Week " << i + 1 << ", " << matchups[i] << std::endl;
	}
	for (int i = 0;i < num_teams; ++i){
		ss << "Team: " << i + 1 << ", Max matchups: " << matchup_limit[i] << ", current matchups: " << matchup_count[i] << std::endl;
	}
	return ss.str();
}

// Send to ostream
std::ostream& operator << (std::ostream& os, const Player& input){
	os << input.ToString();
	return os;
}
