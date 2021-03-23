//5566
#include <iostream>
#include <vector>

int main()
{
	int N, M;
	int chapt = 0;

	std::vector <int> board;
	std::vector <int> dice;
	std::cin >> N >> M;

	board.resize(N);
	dice.resize(M);
	for (size_t i = 0 ; i < N ; i++)
		std::cin >> board[i];
	for (size_t i = 0 ; i < M ; i++)
		std::cin >> dice[i];

	int iter = 0;
	while(chapt < M && iter < N - 1)
	{
		iter += dice[chapt++];
		iter += board[iter];
	}
	printf("%d", chapt);
	return (0);
}
