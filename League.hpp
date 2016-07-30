// This file contains the function prototypes for the League class

#include <vector>
#include <string>
#include <map>
#include <utility>
#include "Player.hpp"

class League{
private:
	int divisions;
	int num_teams;
	int num_weeks;

	std::map<int, std::string> names;

	std::vector<Player> teams;

public:
	League();	// Default constructor - Not to be used
	League(const int& divs, const int& n_teams, const int& n_weeks, const std::vector<Player>& team_list, const std::map<int, std::string>& names_list);	// Constructor with inputs
	League(const League& input);	// Copy constructor
	~League();	// Destructor

	League& operator = (const League& input);	// Assignment operator

	// Getter functions
	int Divisions() const;	// Get the number of divisions
	int Num_Teams() const;	// Get the number of teams
	int Num_Weeks() const;	// Get the number of weeks
	std::vector<Player> Teams() const;	// Get the list of teams
	std::map<int, std::string> TeamNames() const;	// Get the names of the teams
	std::vector<std::pair <int, int> > Week(const int& Week_Number) const;	// Get a vector of matchups for a given week

	// Setter functions
	void Divisions(const int& divs);	// Set the number of divisions
	void Num_Teams(const int& n_teams);	// Set the number of teams
	void Num_Weeks(const int& n_weeks);	// Set the number of weeks
	void Teams(const std::vector<Player>& team_list);	// Set the list of teams
	void TeamNames(const std::map<int, std::string>& name_list);	// Set the names of the teams
	void Week(const std::vector<std::pair <int, int> >& matchup_list, const int& week_number);	// Set the week's matchups

	// Function to generate the schedule
	std::vector<std::vector<std::pair <int, int> > > GenerateSchedule();

	std::string ToString() const;	// Function to print out the information as a string

	friend std::ostream& operator << (std::ostream& os, const League& input);	// Send to ostream

};