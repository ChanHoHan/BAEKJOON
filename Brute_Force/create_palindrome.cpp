#include <iostream>
#include <string>

std::string S;
int S_size;
int ans;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> S;
	S_size = S.size();
}

int find_palindrome(int start, int end)
{
	int cnt = 0;

	while (start >= 0 && end < S_size)
	{
		if (S[start] == S[end])
			cnt+=2;
		else
			break;
		start--;
		end++;
	}
	if (end == S_size)
		return (cnt);
	return (-1);
}

void solve()
{
	int i = 0, cnt;

	while (i < S_size)
	{
		cnt = find_palindrome(i - 1, i + 1) + 1;
		if (cnt > 0)
			break;
		cnt = find_palindrome(i, i + 1);
		if (cnt > 0)
			break;
		i++;
	}
	ans = 2 * S_size - cnt;
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
