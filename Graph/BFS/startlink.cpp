//5014
#include <iostream>
#include <queue>

#define endl "\n"

int F,S,G,U,D;
std::string cant_go;
int ans;
std::queue<std::pair<int, int> > q; // current floor, cnt
bool visited[1000001];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> F >> S >> G >> U >> D;
	cant_go = "use the stairs";
	ans = 0;
}

bool bfs()
{
	q = std::queue<std::pair<int, int> >();
	q.push({S, 0});
	int current_f, dist, q_u, q_d;

	while (!q.empty())
	{
		current_f = q.front().first;
		dist = q.front().second;
		q.pop();
		if (current_f == G)
		{
			ans = dist;
			return (1);
		}
		q_u = current_f + U;
		q_d = current_f - D;
		if (q_u >= 1 && q_u <= F && !visited[q_u])
		{
			visited[q_u] = 1;
			q.push({q_u, dist + 1});
		}
		if (q_d >= 1 && q_d <= F && !visited[q_d])
		{
			visited[q_d] = 1;
			q.push({q_d, dist + 1});
		}

	}
	return (0);
}


void solve()
{
	if(!bfs())
		std::cout << cant_go;
	else
		std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

