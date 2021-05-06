//15649
#include <iostream>
#include <string>
#define endl "\n"
int N, M;
bool visited[9];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M;
}

void permutation(int depth, std::string val)
{
	if (depth == M)
	{
		std::cout << val << endl;
		return ;
	}
	for (int i = 1 ; i <= N ; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		permutation(depth + 1, val + std::to_string(i) + " ");
		visited[i] = 0;
	}
}

void solve()
{
	permutation(0, "");
}

int main()
{
	input();
	solve();
	return (0);
}

