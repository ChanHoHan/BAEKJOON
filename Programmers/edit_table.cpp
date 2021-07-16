#include <string>
#include <vector>
#include <stack>
#include <iostream>

int table[1<<21];
std::stack<int> st;
std::string answer = "";

int seg_sum(int l, int r, int n)
{
    int ans = 0;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += table[l++];
        if (r & 1) ans += table[--r];
    }
    return ans;
}

void update(int idx, int val, int n)
{
	table[idx + n] = val;
	for (idx += n ; idx > 1 ; idx >>= 1)
	{
		table[idx >> 1] = table[idx] + table[idx ^ 1];
	}
}


void init_seg(int n)
{
	for (int i = n - 1 ; i > 0 ; i--)
		table[i] = table[i << 1] + table[i << 1 | 1];
}

int b_search(int start, int end, int num, int flag, int n)
{
	int mid, val, s = start, e = end;

	if (flag)
	{
		while (start <= end)
		{
			mid = (start + end) / 2;
			val = seg_sum(s, mid + 1, n);
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
			val = seg_sum(mid, e + 1, n);
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
	int num, cursor = k , how;
	int x;
	std::string op;

	for (int i = 0 ; i < n ; i++)
		answer += "O";
	for (int i = 0 ; i < n ; i++)
		table[i + n] = 1;
	init_seg(n);
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
			cursor = b_search(cursor + 1, n - 1, num, 1, n);
		}
		else if (op == "U")
		{
			x = 2;
			std::string v = "";
			int d_size = cmd[i].size();
			while (x < d_size)
				v += cmd[i][x++];
			num = std::stoi(v);
			cursor = b_search(0, cursor - 1, num, 0, n);
		}
		else if (op == "C")
		{
			update(cursor, 0, n);
			st.push(cursor);
			answer[cursor] = 'X';
			int plus_how = b_search(cursor + 1, n - 1, 1, 1, n);
			if (plus_how >= 0 && plus_how < n)
				cursor = plus_how;
			else
 		               cursor = b_search(0, cursor - 1, 1, 0, n);
		}
		else if (op == "Z")
		{
			int z_val = st.top();
			st.pop();
			update(z_val, 1, n);
			answer[z_val] = 'O';
		}
	}
	return answer;
}
