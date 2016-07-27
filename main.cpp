#include <iostream>
#include "Player.hpp"

int main(){
	Player Jeff;

	std::vector<int> temp;

	temp.resize(Jeff.Matchups().size());

	temp = Jeff.Matchups();

	for (std::vector<int>::const_iterator iter = temp.begin(); iter != temp.end(); iter++){
		std::cout << *iter << std::endl;
	}

	return 0;
}