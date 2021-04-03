//1874
#include <iostream>
#include <vector>
#include <stack>
#define endl "\n"

std::vector<int> sequence;
std::string ans;
std::stack<int> s;

size_t n;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> n;
	sequence.resize(n);
	for (size_t i = 0 ; i < n ; i++)
		std::cin >> sequence[i];
}

void solve()
{
	int val, next_stack_val, ans_size, save;

	next_stack_val = 1;
	for (size_t i = 0 ; i < n ; i++)
	{
		val = sequence[i];
		if (!s.empty() && s.top() >= val) //pop
		{
			ans_size = ans.size();
			while (val <= s.top())
			{
				ans+="-";
				save = s.top();
				s.pop();
				if (val == save)
					break;
			}
			if (ans_size == ans.size())
			{
				ans = "NO";
				return ;
			}
		}
		else// push
		{
			if (val < next_stack_val) // 다음 넣을 수가 원하는 수보다 크면
			{
				ans = "NO";
				return ;
			}
			if (s.empty())
			{
				s.push(next_stack_val);
				next_stack_val++;
				ans+="+";
			}
			while (val != s.top())
			{
				ans+="+";
				s.push(next_stack_val);
				next_stack_val++;
			}
			ans+="-";
			s.pop();
		}
	}
}

void print_val()
{
	if (ans == "NO")
	{
		std::cout << ans;
		return ;
	}
	for (size_t i = 0 ; i < ans.size() ; i++)
		std::cout << ans[i] << endl;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

