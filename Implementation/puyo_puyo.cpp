#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

char g_map[12][6];
bool visited[12][6];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
std::queue<std::pair<int, int> > q;
std::vector<std::pair<int, int> >save;
int chain;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	std::string tmp;
	input_faster();
	for (int i = 0 ; i < 12 ; i++)
	{
		std::cin >> tmp;
		for (size_t j = 0 ; j < tmp.size() ; j++)
			g_map[i][j] = tmp[j];
	}
}

bool bfs(int y, int x)
{
	int qy,qx,ny,nx;
	int cnt = 1;
	char color = g_map[y][x];

	save.clear();
	visited[y][x] = 1;
	q.push({y, x});
	save.push_back({y,x});
	
	while(!q.empty())
	{
		qy = q.front().first;
		qx = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6 || visited[ny][nx] || color != g_map[ny][nx])
				continue;
			cnt++;
			q.push({ny, nx});
			visited[ny][nx] = 1;
			save.push_back({ny, nx});
		}
	}
	
	if (cnt >= 4)
	{
		for (auto &i : save)
			g_map[i.first][i.second] = '.';
		return (1);
	}
	return (0);
}

bool bfs_check()
{
	bool rtn = 0;

	for (int i = 0; i < 12 ; i++)
		for (int j = 0 ; j < 6 ; j++)
			if(!visited[i][j] && g_map[i][j] != '.' && bfs(i, j))
				rtn = 1;
	return (rtn);
}

void gravity()
{
	bool dot_flag;
	int k;

	for (int j = 0 ; j < 6 ; j++)
	{
		dot_flag = 0;
		for (int i = 11 ; i >= 0 ; i--)
		{
			if (g_map[i][j] == '.')
				dot_flag = 1;
			else if (g_map[i][j] != '.' && dot_flag)
			{
				k = i - 1;
				while (k < 12)
				{
					if (k == 11 && g_map[k][j] == '.')
					{
						g_map[k][j] = g_map[i][j];
						g_map[i][j] = '.';
						break;
					}
					else if (g_map[k + 1][j] != '.' && g_map[k][j] == '.')
					{
						g_map[k][j] = g_map[i][j];
						g_map[i][j] = '.';
						break;
					}
					k++;
				}
			}
		}
		std::cout << std::endl;
	}
}

void solve()
{
	while(bfs_check())
	{
		gravity();
		chain++;
		memset(visited, 0, sizeof(visited));
	}
	
}

void print_val()
{
	std::cout << chain;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

