//1348
#include <iostream>
#include <vector>
#include <queue>

size_t R,C;
std::vector<std::string> g_map;

std::vector<std::vector<int> >c_p_d; // cars and parking lots distance.
std::vector<int> is_oc; // is occupancy ? (the parking lots)

std::vector<std::pair<size_t, size_t> >c_l; // cars location
std::vector<std::pair<size_t, size_t> >p_l; // parking lots location
std::vector<int> c_i; // cars index
std::vector<int> p_i; // parking lots index
std::vector<bool> visited; // d_dfs visited
std::vector<std::pair<int, int> >dir; // direction
std::queue <std::pair<std::pair<int, int>, int> >d_bfs_q;
int dist_max = -1;
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> R >> C;
	g_map.resize(R);
	for (size_t i = 0 ; i < R ; i++)
	{
		g_map[i].resize(C);
		std::cin >> g_map[i];
	}
	dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	ans = -1;
}

void input_val()
{
	int car_index = -1;
	int park_index = -1;
	c_i.reserve(100);
	p_i.reserve(100);
	for(size_t i = 0 ; i < R ; i++)
		for (size_t j = 0 ; j < C ; j++)
		{
			if (g_map[i][j] == 'C')
			{
				c_i.push_back(++car_index);
				c_l.push_back(std::make_pair(i, j));
				g_map[i][j] = 101; //for preventing crash with park_index
			}
			else if (g_map[i][j] == 'P')
			{
				p_i.push_back(++park_index);
				p_l.push_back(std::make_pair(i, j));
				g_map[i][j] = park_index;
			}
			else if (g_map[i][j] == 'X')
				g_map[i][j] = 102;
			else
				g_map[i][j] = 103;
		}
}

void d_bfs(int i) // for calculating distance between cars and parking lots
{
	int y = c_l[i].first; // i
	int x = c_l[i].second; // j
	int q_y, q_x, dist;
	while(!d_bfs_q.empty()) d_bfs_q.pop(); //queue initialization
	visited = std::vector<bool>(R*C, 0); // visited initialization
	d_bfs_q.push(std::make_pair(std::make_pair(y, x), 0));
	while(!d_bfs_q.empty())
	{
		q_y = d_bfs_q.front().first.first;
		q_x = d_bfs_q.front().first.second;
		dist = d_bfs_q.front().second;
		d_bfs_q.pop();
		if (q_y < 0 || q_x < 0 || q_x >= static_cast<int>(C) || q_y >= static_cast<int>(R) || g_map[q_y][q_x] == 102 || visited[q_y * C + q_x])
			continue;
		visited[q_y * C + q_x] = 1;
		if (0 <= g_map[q_y][q_x] && g_map[q_y][q_x] <= 100)
		{
			c_p_d[i][g_map[q_y][q_x]] = dist; // record the distance between park and car
			if (dist > dist_max)
				dist_max = dist;
		}
		for (size_t i = 0 ; i < 4 ; i++)
			d_bfs_q.push(std::make_pair(std::make_pair(q_y + dir[i].first, q_x + dir[i].second), dist+1));
	}
}

void make_c_p_d()
{
	c_p_d.resize(c_i.size(), std::vector<int>(p_i.size(), 0));
	for(size_t i = 0; i < c_i.size() ; i++)
		d_bfs(i);
}

bool dfs(int &b_mid, int index)
{
	for(size_t i = 0 ; i < p_i.size() ; i++)
	{
		if (!c_p_d[index][i] || visited[i] || c_p_d[index][i] > b_mid) // visit , is equal or less than b_mid
			continue;
		visited[i] = true;
		if (is_oc[i] == -1 || dfs(b_mid, is_oc[i]))
		{
			is_oc[i] = index;
			return (true);
		}
	}
	return (false);
}

int dfs_main(int &b_mid)
{
	is_oc = std::vector<int>(p_i.size(), -1);
	int cnt = 0;
	for(size_t i = 0 ; i < c_i.size() ; i++)
	{
		visited = std::vector<bool>(p_i.size(), 0);
		if (dfs(b_mid, i))
			cnt++;
	}
	return (cnt);
}

void binary_search(int b_min, int b_max)
{
	if (b_min > b_max)
		return ;
	int b_mid = (b_min + b_max) >> 1;
	if(static_cast<size_t>(dfs_main(b_mid)) == c_i.size())
	{
		ans = b_mid;
		binary_search(b_min , b_mid - 1);
	}
	else
		binary_search(b_mid + 1, b_max);
}

void solve()
{
	make_c_p_d();
	binary_search(1, dist_max);
}

bool exception_check()
{
	if (p_i.size() < c_i.size())
	{
		std::cout << -1;
		return (0);
	}
	else if (!c_i.size())
	{
		std::cout << 0;
		return (0);
	}
	return (1);
}

int main()
{
	input();
	input_val();
	if(!exception_check())
		return (0);
	solve();
	std::cout << ans;
	return (0);
}
