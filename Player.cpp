// This file contains all of the function definitions for the Player class

#include "Player.hpp"
#include <iostream>
#include <sstream>

// Default constructor
Player::Player() : num_weeks(13) {
	matchups.resize(num_weeks);
}

// Constructor with input
Player::Player(const std::vector<int>& input, const int weeks) : matchups(input), num_weeks(weeks) { }

// Copy constructor
Player::Player(const Player& input): matchups(input.matchups), num_weeks(input.num_weeks) { }

// Destructor
Player::~Player(){ }

// Assignment operator
Player& Player::operator = (const Player& input){
	if (this == &input)
		return *this;

	matchups = input.matchups;
	num_weeks = input.num_weeks;
	return *this;
}

// Getter function
std::vector<int> Player::Matchups() const {
	return matchups;
}

// Setter function
void Player::Matchups(const std::vector<int>& input){
	if (matchups.size() == input.size())
		matchups = input;
//		for (int i = 0; i < matchups.size(); ++i)
//		matchups[i] = input[i];
	else{
		std::cout << "The vectors are not the same size." << std::endl;
	}
}

// Function to print out the information as a string
std::string Player::ToString() const{
	std::stringstream ss;
	ss << "Number of weeks: " << num_weeks << ".  Matchups: ";
	for (int i = 0;i < num_weeks; ++i)
		ss << "Week " << i + 1 << ", " << matchups[i] << ".  ";
	return ss.str();
}

// Send to ostream
std::ostream& operator << (std::ostream& os, const Player& input){
	os << input.ToString();
	return os;
}
