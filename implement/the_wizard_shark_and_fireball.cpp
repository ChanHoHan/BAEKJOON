//20056
#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#define endl "\n"

int N, M, K;
std::vector<std::vector<std::vector<int> > >magic;
std::vector<std::vector<int> > fireball;
std::vector<std::vector<int> > fireball_tmp;
std::vector<std::pair<int, int> >check;
int visited[53][53];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int s_d[4] = {0, 2, 4, 6};
int o_d[4] = {1, 3, 5, 7};

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> M >> K;
	fireball.resize(M, std::vector<int>(6));
	for (int i = 0 ; i < M ; i++)
		for (int j = 1 ; j <= 5 ; j++)
			std::cin >> fireball[i][j];
}

void get_magic(int ind, int &r, int &c, int &m, int &s, int &d)
{
	r = fireball[ind][1];
	c = fireball[ind][2];
	m = fireball[ind][3];
	s = fireball[ind][4];
	d = fireball[ind][5];
}

void move_action(int ind, int r, int c, int s, int d)
{
	int l_dx = (s * N + c + dx[d] * s) % N;
	int l_dy = (s * N + r + dy[d] * s) % N;

	r = !l_dy ? N : l_dy;
	c = !l_dx ? N : l_dx;

	magic[r][c].push_back(ind);
	check.push_back({r, c});
	fireball[ind][1] = r;
	fireball[ind][2] = c;
}

void move()
{
	int r,c,m,s,d;

	for (int i = 0 ; i < fireball.size() ; i++)
	{
		get_magic(i, r, c, m, s, d);
		move_action(i, r, c, s, d);
	}
}

void sum_logic(size_t i, size_t j, int& f_ind)
{
	int m, v, dir, make_dir;
	int ind;

	m = 0;
	v = 0;
	make_dir = 0;
	dir = fireball[magic[i][j][0]][5] % 2;
	for (size_t k = 0 ; k < magic[i][j].size(); k++)
	{
		ind = magic[i][j][k];
		m += fireball[ind][3];
		v += fireball[ind][4];
		if (!make_dir && dir != (fireball[ind][5] % 2))
			make_dir = 1;
			
	}
	m = std::ceil(m / 5);
	v = std::ceil(v / magic[i][j].size());
	if (m == 0)
		return ;
	for (size_t k = 0 ; k < 4 ; k++)
	{
		fireball_tmp.push_back(std::vector<int>());
		if (make_dir) // 다르면
		{
			fireball_tmp[f_ind].push_back(0);
			fireball_tmp[f_ind].push_back(i);
			fireball_tmp[f_ind].push_back(j);
			fireball_tmp[f_ind].push_back(m);
			fireball_tmp[f_ind].push_back(v);
			fireball_tmp[f_ind].push_back(o_d[k]);
		}
		else
		{
			fireball_tmp[f_ind].push_back(0);
			fireball_tmp[f_ind].push_back(i);
			fireball_tmp[f_ind].push_back(j);
			fireball_tmp[f_ind].push_back(m);
			fireball_tmp[f_ind].push_back(v);
			fireball_tmp[f_ind].push_back(s_d[k]);

		}
		f_ind++;
	}
}

void summation()
{
	int y, x, ind;

	ind = 0;
	for(size_t i = 0 ; i < check.size(); i++)
	{
		y = check[i].first;
		x = check[i].second;
		if (visited[y][x])
			continue;
		visited[y][x] = 1;
		if (magic[y][x].size() >= 2)
			sum_logic(y, x, ind);
		else if (magic[y][x].size() == 1)
		{
			fireball_tmp.push_back(std::vector<int>());
			fireball_tmp[ind].push_back(0);
			for (size_t j = 1 ; j <= 5 ; j++)
				fireball_tmp[ind].push_back(fireball[magic[y][x][0]][j]);
			ind++;
		}
	}
}

void solve()
{
	while (K--)
	{
		magic = std::vector<std::vector<std::vector<int> > >(53, std::vector<std::vector<int> >(53));
		fireball_tmp = std::vector<std::vector<int> >();
		
		memset(visited, 0, sizeof(visited));
		check = std::vector<std::pair<int, int> >();

		move();
		summation();
		fireball = fireball_tmp;
	}
}

void print_val()
{
	int ans = 0;

	for (size_t i = 0 ; i < fireball.size(); i++)
		ans += fireball[i][3];
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

