//4435
#include <iostream>

int main()
{
	int T;
	int gandalf_power[7] = {1, 2, 3, 3, 4, 10};
	int gandalf[7];
	int sauron_power[8]= {1, 2, 2, 2, 3, 5, 10};
	int sauron[8];
	int gandalf_score, sauron_score;
	std::cin >> T;
	for(int i = 0 ; i < T ; i++)
	{
		gandalf_score = 0;
		sauron_score = 0;
		for(int j = 0 ; j < 6; j++)
			std::cin >> gandalf[j];
		for(int j = 0 ; j < 6; j++)
			gandalf_score += gandalf_power[j] * gandalf[j];
		for(int j = 0 ; j < 7 ; j++)
			std::cin >> sauron[j];
		for(int j = 0 ; j < 7 ; j++)
			sauron_score += sauron_power[j] * sauron[j];
		std::cout << "Battle " << i+1 << ": ";
		if (gandalf_score > sauron_score)
			std::cout << "Good triumphs over Evil\n";
		else if (gandalf_score < sauron_score)
			std::cout << "Evil eradicates all trace of Good\n";
		else
			std::cout << "No victor on this battle field\n";
	}
	return (0);
}

