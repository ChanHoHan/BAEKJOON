//17281
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <vector>
#define endl "\n"

int N;
int max_score, score;
int record[51][10];
std::vector<int> players;
std::queue<int> q;
int base_condition[4];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N;
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= 9 ; j++)
			std::cin >> record[i][j];
 	players = {2, 3, 4, 5, 6, 7, 8, 9};
}

void make_one()
{
	if (base_condition[3])
	{
		score++;
		base_condition[3] = 0;
	}
	if (base_condition[2])
	{
		base_condition[3] = 1;
		base_condition[2] = 0;
	}
	if (base_condition[1])
		base_condition[2] = 1;
	base_condition[1] = 1;
}

void make_two()
{
	if (base_condition[3])
	{
		score++;
		base_condition[3] = 0;
	}
	if (base_condition[2])
		score++;
	if (base_condition[1])
	{
		base_condition[3] = 1;
		base_condition[1] = 0;
	}
	base_condition[2] = 1;
}

void make_three()
{
	if (base_condition[3])
		score++;
	if (base_condition[2])
	{
		score++;
		base_condition[2] = 0;
	}
	if (base_condition[1])
	{
		score++;
		base_condition[1] = 0;
	}
	base_condition[3] = 1;
}

void make_homerun()
{
	for (int i = 1 ; i <= 3 ; i++)
		if (base_condition[i])
			score++;
	score++;
	memset(base_condition, 0, sizeof(base_condition));
}

void make_run(int player_rec)
{
	if (player_rec == 1)
		make_one();
	else if (player_rec == 2)
		make_two();
	else if (player_rec == 3)
		make_three();
	else if (player_rec == 4)
		make_homerun();
}

void simulation()
{
	int _N = N;
	int ining = 0;
	int pl; // 선수
	int out_count;
	score = 0;

	while (_N--)
	{
		out_count = 0;
		ining++; // 다음 이닝
		memset(base_condition, 0, sizeof(base_condition));
		while(out_count < 3)
		{
			pl = q.front(); // 타석에 등장
			q.pop();
			if (record[ining][pl] >= 1 && record[ining][pl] <= 4)
				make_run(record[ining][pl]);
			else
				out_count++;
			q.push(pl);
		}
	}
}

void solve()
{
	do {
		q = std::queue<int>();
		for (size_t i = 0 ; i < players.size(); i++)
		{
			if (i == 3)
				q.push(1);
			q.push(players[i]);
		}
		simulation();
		max_score = std::max(max_score, score);
	}while(next_permutation(players.begin(), players.end()));
}

void print_val()
{
	std::cout << max_score;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

