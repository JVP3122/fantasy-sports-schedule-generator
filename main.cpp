#include <iostream>
#include "Player.hpp"
#include "League.hpp"

int main(){
	Player Jeff;
	League Test_League;

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

	return 0;
}