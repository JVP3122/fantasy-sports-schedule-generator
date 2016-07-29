// This file contains function prototypes for the Player class

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<vector>
#include<string>

class Player{
	private:
		int num_weeks;	// The number of weeks in the season (I suspect I'll be changing this in the future)
		int num_teams;	// The number of teams in the league
		int division;	// Returns the division the team is in, if any
		int place;		// A variable to keep track of different teams in the league
		std::string name;	// Team name
		std::vector<int> matchups;	// Vector that holds this team's matchups
		std::vector<int> matchup_limit;	// Vector that defines the max number of times a team can play other teams
		std::vector<int> matchup_count;	// Vector that tracks how many times a player is scheduled to play other teams

	public:
		Player();	// Default constructor - Not to be used
		Player(const std::vector<int>& limit, const std::vector<int>& count, const int weeks, const int teams, const int div, const int rank, const std::string team_name);	// Constructor with input
		Player(const Player& input);	// Copy constructor
		~Player();	// Destructor

		Player& operator = (const Player& input);	// Assignment operator

		// Getter functions
		std::vector<int> Matchups() const;	// Matchups
		std::vector<int> Matchup_Count() const; // Matchup current count
		std::vector<int> Matchup_Limit() const;	// Matchup limit
		int Division() const;	// The team's division
		int Place() const;	// The team's placement in the league
		int Num_Weeks() const;	// The number of weeks the player has associated with his/her team
		int Num_Teams() const;	// The number of teams in the league that each player has associated with his/her team
		std::string Name() const;	// The team's name

		// Setter functions
		void Matchups(const std::vector<int>& input);	// Matchups
		void Matchup_Count(const std::vector<int>& input);	// Matchup current count
		void Matchup_Limit(const std::vector<int>& input);	// Matchup limit
		void Division(const int& input);	// Division
		void Place(const int& rank);	// Place
		void Name(const std::string& team_name);	// The team's name

		std::string ToString() const;	// Function to print out the information as a string

		friend std::ostream& operator << (std::ostream& os, const Player& input);	// Send to ostream


};

#endif // !PLAYER_HPP