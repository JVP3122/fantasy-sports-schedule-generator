// This file contains all of the function definitions for the Player class

#include "Player.hpp"
#include <iostream>

Player::Player() : num_weeks(13) {
	matchups.resize(num_weeks);
}

Player::Player(const std::vector<int>& input, const int weeks) : matchups(input), num_weeks(weeks) { }

Player::Player(const Player& input): matchups(input.matchups), num_weeks(input.num_weeks) { }

Player::~Player(){ }

Player& Player::operator = (const Player& input){
	if (this == &input)
		return *this;

	matchups = input.matchups;
	num_weeks = input.num_weeks;
	return *this;
}

std::vector<int> Player::Matchups() const {
	return matchups;
}

void Player::Matchups(const std::vector<int>& input){
	if (matchups.size() == input.size())
		matchups = input;
	else{
		std::cout << "The vectors are not the same size." << std::endl;
	}
}