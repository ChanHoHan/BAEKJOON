//3425
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#define endl "\n"

int g_max = 1e9;
void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
}

void num_operation(int &num_val_pointer, std::stack<long long>& s, std::vector<int> num_val)
{
	s.push(num_val[num_val_pointer++]);
}

bool pop_operation(std::stack<long long> &s)
{
	if (s.size() == 0)
		return (0);
	s.pop();
	return (1);
}

void inv_operation(std::stack<long long> &s)
{
	long long temp = s.top();
	s.pop();
	s.push(-temp);
}

bool dup_operation(std::stack<long long> &s)
{
	if (s.size() == 0)
		return (0);
	long long temp = s.top();
	s.pop();
	s.push(temp);
	s.push(temp);
	return (1);
}

bool swp_operation(std::stack<long long> &s)
{
	if (s.size() <= 1)
		return (0);
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	s.push(a);
	s.push(b);
	return (1);
}

bool add_operation(std::stack<long long> &s)
{
	if (s.size() <= 1)
		return (0);
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (a + b > g_max)
		return (0);
	s.push(a + b);
	return (1);
}

bool sub_operation(std::stack<long long> &s)
{
	if (s.size() <= 1)
		return (0);
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (b - a < -g_max)
		return (0);
	s.push(b - a);
	return (1);
}

bool mul_operation(std::stack<long long> &s)
{
	if (s.size() <= 1)
		return (0);
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (std::abs(a * b) > g_max)
		return (0);
	s.push(a * b);
	return (1);
}

bool div_operation(std::stack<long long> &s)
{
	if (s.size() <= 1)
		return (0);
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (a == 0)
		return (0);
	long long val = std::abs(b) / std::abs(a);
	if ((a < 0 && b > 0) || (a > 0 && b < 0))
		val = -val;
	s.push(val);
	return (1);
}

bool mod_operation(std::stack<long long> &s)
{
	if (s.size() <= 1)
		return (0);
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (a == 0)
		return (0);
	long long val = std::abs(b) % std::abs(a);
	if (b < 0)
		val = -val;
	s.push(val);
	return (1);
}

bool operation(std::stack<long long>& s, std::vector<std::string> op, std::vector<int> num_val)
{
	int num_val_pointer = 0, op_size = op.size();

	for (int i = 0 ; i < op_size ; i++)
	{
		if (op[i] == "NUM")
			num_operation(num_val_pointer, s, num_val);
		else if (op[i] == "POP" && !pop_operation(s))
			return (0);
		else if (op[i] == "INV")
			inv_operation(s);
		else if (op[i] == "DUP" && !dup_operation(s))
			return (0);
		else if (op[i] == "SWP" && !swp_operation(s))
			return (0);
		else if (op[i] == "ADD" && !add_operation(s))
			return (0);
		else if (op[i] == "SUB" && !sub_operation(s))
			return (0);
		else if (op[i] == "MUL" && !mul_operation(s))
			return (0);
		else if (op[i] == "DIV" && !div_operation(s))
			return (0);
		else if (op[i] == "MOD" && !mod_operation(s))
			return (0);
	}
	return (1);
}

void solve()
{
	std::string inp;
	int tmp, N;
	std::vector<std::string> op;
	std::vector<int> num_val;
	std::stack<long long> s;

	while(true)
	{
		std::cin >> inp;
		if (inp == "QUIT")
			break;
		if (inp != "END")
			op.push_back(inp);
		if (inp == "NUM")
		{
			std::cin >> tmp;
			num_val.push_back(tmp);
		}
		else if (inp == "END")
		{
			std::cin >> N;
			int tmp;
			for (int i = 0 ; i < N ; i++)
			{
				s = std::stack<long long> ();
				std::cin >> tmp;
				s.push(tmp);
				if(!operation(s, op, num_val) || s.size() != 1)
					std::cout << "ERROR" << endl;
				else
					std::cout << s.top() << endl;
			}
			op = std::vector<std::string>();
			num_val = std::vector<int>();
			std::cout << endl;
		}
	}
}

int main()
{
	input();
	solve();
	return (0);
}
