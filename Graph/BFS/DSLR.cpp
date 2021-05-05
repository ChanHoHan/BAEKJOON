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

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> T;
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

inline int function_handler(int i, int a)
{
	if (i == 0)
		return (D(a));
	else if (i == 1)
		return (S(a));
	else if (i == 2)
		return (L(a));
	else
		return (R(a));
}

inline char operation(int i)
{
	if (i == 0)
		return ('D');
	else if (i == 1)
		return ('S');
	else if (i == 2)
		return ('L');
	else
		return ('R');
}

inline void bfs()
{
	std::string qs, ns;
	int val, nval;

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
			nval = function_handler(i, val);
			if (nval == B)
			{
				std::cout << qs + operation(i) << endl;
				return ;
			}
			if (visited[nval])
				continue; 
			visited[nval] = 1;
			ns = qs + operation(i);
			q.push({ns, nval});
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

