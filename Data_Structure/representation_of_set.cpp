//1717
#include <iostream>
#define endl "\n"
int n, m;

int root[1000001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> n >> m;
}


int _find(int x)
{
	if (root[x] == x)
		return (x);
	else
		return (root[x] = _find(root[x]));
}

void _union(int a, int b)
{
	a = _find(a);
	b = _find(b);

	root[a] = b;
}


void solve()
{
	int fl, a, b;
	for (int i = 1 ; i <= 1000000 ; i++)
		root[i] = i;

	for (int i = 0 ; i < m ; i++)
	{
		std::cin >> fl >> a >> b;
		if (!fl) // 합침
		{
			_union(a, b);
		}
		else
		{
			a = _find(a);
			b = _find(b);
			if (a == b)
				std::cout << "YES" << endl;
			else
				std::cout << "NO" << endl;
		}
	}
}

int main()
{
	input();
	solve();
	return (0);
}
