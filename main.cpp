// The main file that creates the league and generates the schedule, also outputting the schedule to a csv file

#include <iostream>
#include "Player.hpp"
#include "League.hpp"
#include <fstream>
#include <unistd.h>
#include <algorithm>

int main(){

	int divs = 2;	// Set the number of divisions
	int weeks = 13;	// Set the number of weeks
	int teams = 14;	// Set the number of teams

	// Create a map of team names
	std::map<int,std::string> Team_List;
	Team_List[0] = "Jeff P";
	Team_List[1] = "Nico";
	Team_List[2] = "Andrew";
	Team_List[3] = "Doug";
	Team_List[4] = "Dennis";
	Team_List[5] = "Austin";
	Team_List[6] = "Matt";
	Team_List[7] = "Rob";
	Team_List[8] = "Chris";
	Team_List[9] = "Alan";
	Team_List[10] = "Jeff W";
	Team_List[11] = "James";
	Team_List[12] = "Ajay";
	Team_List[13] = "Jack";

	// Instantiate a vector of Players to be passed into the League class
	std::vector<Player> PlayerVector;

	// Instantiate Player objects and push each one to the back of the vector
	for (int i = 0; i < teams; ++i){
		int division;	// Instantiate the division that Player i is in
		std::vector<int> Matchup_Limits;	// Instantiate a vector for the matchup limits for player i
		std::vector<int> Matchup_Count(teams);	// Instantiate a vector for the current count of matchups for player i

		// If player i is in the first half of the preliminary "standings"
		if (i < 7){
			division = 1;	// Set the division = 1

			// Set matchup limits for a first division team - twice against teams in the same division, once in other division
			for (int j = 0; j < teams; ++j){
				if (j < 7)
					Matchup_Limits.push_back(2);
				else
					Matchup_Limits.push_back(1);
			}
		}
		else{
			division = 2;	// Set the division = 2

			// Set matchup limits for a second division team - twice against teams in the same division, once in other division
			for (int j = 0; j < teams; ++j){
				if (j >= 7)
					Matchup_Limits.push_back(2);
				else
					Matchup_Limits.push_back(1);
			}
		}

		// Set the max number of times a team can play itself equal to 0
		Matchup_Limits[i] = 0;

		// Instantiate a Player object with the corresponding attributes
		PlayerVector.push_back(Player(Matchup_Limits,Matchup_Count,weeks,teams,divs,i,0,2,Team_List[i]));
	}

	// Instantiate the League with the necessary inputs
	League MonkeysWithCrayons(divs,teams,weeks,0,2,PlayerVector,Team_List);

	// Print test output
	std::cout << MonkeysWithCrayons << std::endl << std::endl;


	// Loop to run through the schedule generation until there are no instances where a team has no matchup
	int double_zeros = 1;	// A zero in the team location and opponent location in the pair
	int count = 0;	// While loop count
	int double_zero_min_val = 20;	// Variable for output at the end the minimum double_zero value
	std::vector<std::vector<std::pair<int, int> > > Schedule;
	while (double_zeros > 0 && count < 600){	// count < 600 solely to set the time taken at 5 minutes
		double_zeros = 0;	// Reset double_zeros to 0
		Schedule = MonkeysWithCrayons.GenerateSchedule();

		for (std::vector<std::vector<std::pair<int, int> > >::const_iterator row = Schedule.begin(); row != Schedule.end(); ++row){
			for (std::vector<std::pair<int, int> >::const_iterator col = row->begin(); col != row->end(); ++col){
				if (col->first == 0 && col->second == 0)
					double_zeros++;	// If an individual pair has both elements = 0 then increment the double_zeros variable
			}
		}
		int sec = int(1*1000000);	// Pause for the random number generator
    	usleep(sec);	// Pause for the random number generator
		std::cout.flush();
		count++;	// Increment the count variable
		std::cout << "Count: " << count << ", double_zeros = " << double_zeros << std::endl;	// Display the count and current double_zeros value
		double_zero_min_val = std::min(double_zeros,double_zero_min_val);	// Re-assign the min double_zeros value
	}
	std::cout << "Min double_zeros value: " << double_zero_min_val << std::endl; // Print the min double_zeros value at the end of the loop

	// Write the schedule in numeric format to a csv file
	std::ofstream myfile;
	myfile.open("Basic Schedule.csv");
	int week_val = 1;
	for (std::vector<std::vector<std::pair<int, int> > >::const_iterator row = Schedule.begin(); row != Schedule.end(); ++row){
		myfile << "Week " << week_val << std::endl;
		for (std::vector<std::pair<int, int> >::const_iterator col = row->begin(); col != row->end(); ++col){
			myfile << col->first << "," << col->second << ",,";
		}
		myfile << std::endl;
		++week_val;
	}
	myfile.close();

	return 0;
}