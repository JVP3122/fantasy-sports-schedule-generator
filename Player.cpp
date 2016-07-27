// This file contains all of the function definitions for the Player class

#include "Player.hpp"

Player::Player() : num_teams(14), num_weeks(13) {
	matchups.resize(num_weeks);
}

Player::~Player(){}

std::vector<int> Player::Matchups() const {
	return matchups;
}

void Player::Matchups(const std::vector<int> input){
	matchups = input;
}