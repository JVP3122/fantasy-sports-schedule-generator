// This file contains function prototypes for the Player class

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<vector>
#include<string>

class Player{
	private:
		int num_weeks;	// The number of weeks in the season (I suspect I'll be changing this in the future)
		std::vector<int> matchups;	// Vector that holds this team's matchups
	public:
		Player();	// Default constructor
		Player(const std::vector<int>& input, const int weeks);	// Constructor with input
		Player(const Player& input);	// Copy constructor
		~Player();	// Destructor

		Player& operator = (const Player& input);	// Assignment operator

		std::vector<int> Matchups() const;	// Getter function

		void Matchups(const std::vector<int>& input);	// Setter function

		std::string ToString() const;	// Function to print out the information as a string

		friend std::ostream& operator << (std::ostream& os, const Player& input);	// Send to ostream


};

#endif // !PLAYER_HPP