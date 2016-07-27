// This file contains function prototypes for the Player class

#include<vector>

class Player{
	private:
		int num_weeks;	// The number of weeks in the season (I suspect I'll be changing this in the future)
		int num_teams;	// The number of teams in the league - This will likely be moved into the League functionality
		std::vector<int> matchups;	// Vector that holds this team's matchups
	public:
		Player();	// Default constructor
/*		Player(std::vector<int> input);	// Constructor with matchup input
		Player(const int weeks, const int teams);	// Constructor with other input
		Player(const Player& input);	// Copy constructor
*/		~Player();	// Destructor

//		Player& operator = (const Player& input);	// Assignment operator

		std::vector<int> Matchups() const;	// Getter function

		void Matchups(const std::vector<int> input);	// Setter function
};