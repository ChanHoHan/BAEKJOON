//9019
#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
#define endl "\n"

int T, A, B;
std::queue<std::pair<std::string, int> > q;
bool visited[10001];
const char op[4] = {'D', 'S', 'L', 'R'};
int (*fp[4])(int);

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

inline int D(int a)
{
	return (a * 2 % 10000);
}

inline int S(int a)
{
	return (a == 0 ? 9999 : a - 1); 
}

inline int L(int a)
{
	return (((a / 1000) + (a * 10)) % 10000);
}

inline int R(int a)
{
	return ((a % 10) * 1000 + a / 10);
}

void input()
{
	io_faster();
	std::cin >> T;
	fp[0] = D;
	fp[1] = S;
	fp[2] = L;
	fp[3] = R;
}

inline void bfs()
{
	std::string qs, n_s;
	int val, n_val;

	q = std::queue<std::pair<std::string, int> > ();
	std::memset(visited, 0, sizeof(visited));
	q.push({"", A});
	while (!q.empty())
	{
		qs = q.front().first;
		val = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			n_val = fp[i](val);
			if (n_val == B)
			{
				std::cout << qs + op[i] << endl;
				return ;
			}
			if (visited[n_val])
				continue; 
			visited[n_val] = 1;
			n_s = qs + op[i];
			q.push({n_s, n_val});
		}
	}
}

inline void solve()
{
	std::cin >> A >> B;
	bfs();
}

int main()
{
	input();
	while (T--)
		solve();
	return (0);
}

