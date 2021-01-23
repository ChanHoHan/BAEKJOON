//2191
#include <iostream>
#include <vector>

int N, M;
double S, V;
std::vector<std::pair<double, double> >voles;
std::vector<std::pair<double, double> >holes;
std::vector<std::vector<int> >v_h_p; //connectable between voles ans holes (index)
std::vector<bool> visited;
std::vector<int> is_oc;
double cal_distance(double &x1, double &y1, double &x2, double &y2)
{
	double x = x2 - x1;
	double y = y2 - y1;
	return (x*x + y*y);
}
void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	size_t i = -1;
	input_faster();
	std::cin >> N >> M >> S >> V;
	voles.resize(N);
	holes.resize(M);
	while(++i < static_cast<size_t>(N))
		std::cin >> voles[i].first >> voles[i].second;
	i = -1;
	while(++i < static_cast<size_t>(M))
		std::cin >> holes[i].first >> holes[i].second;
}

bool dfs(size_t index)
{
	for(size_t i = 0 ; i < static_cast<size_t>(M); i++)
	{
		if (visited[i] || !v_h_p[index][i])
			continue;
		visited[i] = true;
		if (is_oc[i] == -1 || dfs(is_oc[i]))
		{
			is_oc[i] = index;
			return (true);
		}
	}
	return (false);
}

size_t cal_main() //being eaten by eagle
{
	size_t i = -1;
	size_t cnt = 0;
	is_oc = std::vector<int> (M, -1);
	while(++i < static_cast<size_t>(N) && cnt < M)
	{
		visited = std::vector<bool> (M, 0);
		if(dfs(i))
			cnt++;
	}
	return (cnt);
}

void preset()
{
	size_t i = -1;
	size_t j;
	v_h_p.resize(N);
	while(++i < static_cast<size_t>(N))
	{
		j = -1;
		v_h_p[i].resize(M, 0);
		while(++j < static_cast<size_t>(M))
			if ((cal_distance(voles[i].first, voles[i].second, holes[j].first, holes[j].second)) <= V*V*S*S)
				v_h_p[i][j] = 1;
	}	
}

int main()
{
	input();
	preset();
	std::cout << N - cal_main();
	return (0);
}

