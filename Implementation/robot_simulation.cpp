//2174
#include <iostream>
#include <vector>

int A, B, N, M;
int g_map[101][101];
std::vector<std::pair<std::pair<int, int>, char> >robots;
std::vector<std::pair<int, std::pair<char, int> > >inst;
int x,y;
char dr[4] = {'E', 'S', 'W', 'N'};

int dy[4] = {0, -1, 0, 1};//ESWN
int dx[4] = {1, 0, -1, 0};

int get_dir_index(char ch)
{
	if (ch == 'E')
		return (0);
	else if (ch == 'S')
		return (1);
	else if (ch == 'W')
		return (2);
	else
		return (3);
}
void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> A >> B;
	std::cin >> N >> M;
	robots.resize(N);
	inst.resize(M);
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> robots[i].first.first >> robots[i].first.second >> robots[i].second;
		g_map[robots[i].first.second][robots[i].first.first] = (i + 1);
	}
	for (int i = 0 ; i < M ; i++)
		std::cin >> inst[i].first >> inst[i].second.first >> inst[i].second.second;

}

bool operation(char op, int num)
{
	int ind = get_dir_index(robots[num - 1].second);
	if (op == 'L')
	{
		ind = ind - 1;
		if (ind < 0)
			ind = 3;
		robots[num - 1].second = dr[ind];
	}
	else if (op == 'R')
	{
		ind = (ind + 1) % 4;
		robots[num - 1].second = dr[ind];
	}
	else if (op == 'F')
	{
		int y = robots[num - 1].first.second;
		int x = robots[num - 1].first.first;
		g_map[y][x] = 0;
		y = y + dy[ind];
		x = x + dx[ind];
		if (y <= 0 || y > B || x <= 0 || x > A)
		{
			std::cout << "Robot "<< num<<" crashes into the wall";
				return (1);
		}
		else if (g_map[y][x])
		{
			std::cout << "Robot "<< num <<" crashes into robot " << g_map[y][x];
				return (1);
		}
		g_map[y][x] = num;
		robots[num - 1].first.first = x;
		robots[num - 1].first.second = y;
	}
	return (0);
}

void solve()
{
	int robot_num, op, times;
	int y, x;
	char dir;

	for (int i = 0 ; i < M ; i++)
	{
		robot_num = inst[i].first;
		op = inst[i].second.first;
		times = inst[i].second.second;
		x = robots[robot_num - 1].first.first;
		y = robots[robot_num - 1].first.second;
		while (times--)
			if(operation(op, robot_num))
				return ;
	}
	std::cout << "OK";
}

int main()
{
	input();
	solve();
	return (0);
}

