//8911
#include <iostream>
#define endl "\n"

int T;
std::string move;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};//NESW

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> T;
}

inline void make_max_min(int x, int y, int &max_y, int &min_y, int &max_x, int &min_x)
{
	if (max_y < y)
		max_y = y;
	if (min_y > y)
		min_y = y;
	if (max_x < x)
		max_x = x;
	if (min_x > x)
		min_x = x;
}

inline void solve()
{
	int y = 500, x = 500, dir = 0, max_y = 500, max_x = 500,  min_y = 500, min_x = 500;
	
	std::cin >> move;
	for (size_t i = 0 ; i < move.size() ; i++)
	{
		if (move[i] == 'F')
		{
			x = x + dx[dir];
			y = y + dy[dir];
			make_max_min(x, y, max_y, min_y, max_x, min_x);
		}
		else if (move[i] == 'B')
		{
			x = x + dx[(dir + 2) % 4];
			y = y + dy[(dir + 2) % 4];
			make_max_min(x, y, max_y, min_y, max_x, min_x);
		}
		else if (move[i] == 'L')
			dir = (dir + 3) % 4;
		else if (move[i] == 'R')
			dir = (dir + 1) % 4;
	}
	std::cout << (max_y - min_y) * (max_x - min_x) << endl;
}

int main()
{
	input();
	while (T--)
		solve();
	return (0);
}

