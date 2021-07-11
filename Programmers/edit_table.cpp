#include <string>
#include <vector>
#include <stack>
#include <iostream>

int table[1<<21];
std::stack<int> st;
std::string answer = "";

int seg_sum(int node, int s, int e, int l, int r)
{
	if (r < s || e < l)
		return (0);
	if (l <= s && e <= r)
		return (table[node]);
	else
		return (seg_sum(node * 2, s, (s + e) / 2 , l, r) + seg_sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

void update(int node, int s, int e, int idx, int v)
{
	if (idx < s || e < idx)
		return ;
	if (s == e)
		table[node] = v;
	else
	{
		update(node * 2, s, (s + e) / 2, idx, v);
		update(node * 2 + 1, (s + e) / 2 + 1 , e, idx, v);
		table[node] = table[node * 2] + table[node * 2 + 1];
	}
}

void init_seg(int node, int s, int e)
{
	if (s == e)
		table[node] = 1;
	else
	{
		init_seg(node * 2, s, (s + e) / 2);
		init_seg(node * 2 + 1, (s + e) / 2 + 1, e);
		table[node] = table[node * 2] + table[node * 2 + 1];
	}
}

int b_search(int start, int end, int num, int flag, int n)
{
	int mid, val, s = start, e = end;

	if (flag)
	{
		while (start <= end)
		{
			mid = (start + end) / 2;
			val = seg_sum(1, 1, n, s, mid);
			if (val >= num)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return (start);
	}
	else // up
	{
		while (start <= end)
		{
			mid = (start + end) / 2;
			val = seg_sum(1, 1, n, mid, e);
			if (val >= num)
				start = mid + 1;
			else
				end = mid - 1;
		}
		return (end);
	}

	return (0);
}

std::string solution(int n, int k, std::vector<std::string> cmd) {
	int cmd_size = cmd.size();
	int num, cursor = k + 1, how;
	int x;
	std::string op;

	for (int i = 0 ; i < n ; i++)
		answer += "O";
	init_seg(1, 1, n);
	for (int i = 0 ; i < cmd_size ; i++)
	{
		op = cmd[i][0];
		if (op == "D")
		{
			x = 2;
			std::string v = "";
			int d_size = cmd[i].size();
			while (x < d_size)
				v += cmd[i][x++];
			num = std::stoi(v);
			how = b_search(cursor + 1, n, num, 1, n);
			cursor = how;
		}
		else if (op == "U")
		{
			x = 2;
			std::string v = "";
			int d_size = cmd[i].size();
			while (x < d_size)
				v += cmd[i][x++];
			num = std::stoi(v);
			how = b_search(1, cursor - 1, num, 0, n);
			cursor = how;
		}
		else if (op == "C")
		{
			update(1, 1, n, cursor, 0);
			st.push(cursor);
			answer[cursor - 1] = 'X';
			int plus_how = b_search(cursor + 1, n, 1, 1, n);
			int minus_how = b_search(1, cursor - 1, 1, 0, n);
			if (plus_how > 0 && plus_how <= n)
				cursor = plus_how;
			else
				cursor = minus_how;
		}
		else if (op == "Z")
		{
			int z_val = st.top();
			st.pop();
			update(1, 1, n, z_val, 1);
			answer[z_val - 1] = 'O';
		}
	}
	return answer;
}

int main()
{
	std::cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"});
}
