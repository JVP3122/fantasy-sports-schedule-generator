#include <iostream>
#include "Player.hpp"
#include "League.hpp"

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
		PlayerVector.push_back(Player(Matchup_Limits,Matchup_Count,weeks,teams,divs,i,Team_List[i]));
	}

	std::vector<int> Temp_Limit_Vec = PlayerVector[3].Matchup_Count();
//	for (std::vector<int>::const_iterator it = Temp_Limit_Vec.begin(); it != Temp_Limit_Vec.end(); ++it)
//		std::cout << *it << " ";
//	std::cout << std::endl;

	// Instantiate the League with the necessary inputs
	League MonkeysWithCrayons(divs,teams,weeks,PlayerVector,Team_List);

	// Print test output
	std::cout << MonkeysWithCrayons << std::endl << std::endl;

	// Set the first week to the preliminarily generated schedule
//	MonkeysWithCrayons.Week(MonkeysWithCrayons.GenerateSchedule(),0);

	// Check functionality of the Week Getter function
	std::vector<std::vector<std::pair<int, int> > > Schedule = MonkeysWithCrayons.GenerateSchedule();

	int week_val = 1;
	for (std::vector<std::vector<std::pair<int, int> > >::const_iterator row = Schedule.begin(); row != Schedule.end(); ++row){
		std::cout << "Week " << week_val << std::endl;
		for (std::vector<std::pair<int, int> >::const_iterator col = row->begin(); col != row->end(); ++col){
			std::cout << Team_List[col->first] << " vs " << Team_List[col->second] << std::endl;
		}
		std::cout << std::endl;
		++week_val;
	}

	// Test printout of the generated schedule
//	std::cout << "Week 1 Matchups" << std::endl;
//
//	for (std::vector<std::pair<int, int> >::const_iterator iter = Week_One_Matchups.begin(); iter != Week_One_Matchups.end(); ++iter){
//		std::cout << Team_List[iter->first] << " vs " << Team_List[iter->second] << std::endl;
//	}

	// Checking to see that an arbitrary matchup_limit vector was appropriately set
//	std::vector<int> Temp_Limit_Vec = PlayerVector[3].Matchup_Limit();
//	for (std::vector<int>::const_iterator it = Temp_Limit_Vec.begin(); it != Temp_Limit_Vec.end(); ++it)
//		std::cout << *it << " ";
//	std::cout << std::endl;

/*

	std::vector<int> TeamNumberVector;

	Player JeffP;
	Player Nico;
	Player Andrew;
	Player Doug;
	Player Dennis;
	Player Austin;

	for (std::map<int,std::string>::const_iterator iter = Team_List.begin(); iter != Team_List.end(); ++iter)
		TeamNumberVector.push_back(iter->first);
	
	// Instantiate the League
	League MonkeysWithCrayons;

	MonkeysWithCrayons.TeamNames(Team_List);

	std::cout << MonkeysWithCrayons << std::endl << std::endl;

	League Test_League;

	std::cout << Test_League << std::endl;

/*	Player Jeff;

	std::cout << Jeff.Matchups().size() << std::endl;

	std::vector<int> games;

	for (int i = 0;i < Jeff.Matchups().size();++i){
		games.push_back(i + 1);
	}

	int games_counter = 0;
	for (std::vector<int>::const_iterator iter = Jeff.Matchups().begin(); iter != Jeff.Matchups().end(); iter++){
		std::cout << "Jeff.Matchups() = " << *iter << ", Games = " << games[games_counter] << std::endl;
		games_counter++;
	}

	std::cout << std::endl;

	Jeff.Matchups(games);

	std::vector<int> MatchupVec;
	MatchupVec = Jeff.Matchups();

	std::cout << Jeff << std::endl;

	for (std::vector<int>::const_iterator iter = MatchupVec.begin(); iter != MatchupVec.end(); iter++){
		std::cout << *iter << std::endl;
	}

	for (int i = 0; i < Jeff.Matchups().size(); ++i){
		std::cout << Jeff.Matchups()[i] << std::endl;
	}

	std::cout << Test_League << std::endl;
	std::vector<Player> temp_vector = Test_League.Teams();
	std::cout << temp_vector[2] << std::endl;

	std::map<int, std::string> names;
	names[0] = "Jeff";
	names[1] = "Ajay";
	names[2] = "James";
	names[3] = "Jack";
	Test_League.TeamNames(names);

	std::map<int, std::string> temp_map = Test_League.TeamNames();
	
	for (std::map<int, std::string>::const_iterator iter = temp_map.begin(); iter != temp_map.end(); ++iter)
		std::cout << iter->second << std::endl;
*/
	return 0;
}