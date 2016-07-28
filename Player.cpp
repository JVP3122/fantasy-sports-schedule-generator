// This file contains all of the function definitions for the Player class

#include "Player.hpp"
#include <iostream>
#include <sstream>

// Default constructor
Player::Player() : num_weeks(13), num_teams(14), division(1), place(0) {
	matchups.resize(num_weeks);
	matchup_limit.resize(num_teams);
	matchup_count.resize(num_teams);
}

// Constructor with input
Player::Player(const std::vector<int>& week_count, const std::vector<int>& limit, const std::vector<int>& count, const int weeks, const int teams, const int div, const int rank) : matchups(week_count), matchup_limit(limit), matchup_count(count), num_weeks(weeks), num_teams(teams), division(div), place(rank) { }

// Copy constructor
Player::Player(const Player& input): matchups(input.matchups), matchup_limit(input.matchup_limit), matchup_count(input.matchup_count), num_weeks(input.num_weeks), num_teams(input.num_teams), division(input.division), place(input.place) { }

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

// Function to print out the information as a string
std::string Player::ToString() const{
	std::stringstream ss;
	ss << "Team: " << place << ", Division: " << division << ".  Matchups: " << std::endl;
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
