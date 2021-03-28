//13335
#include <iostream>
#include <queue>

int n, w, L;
std::queue<int> q; // q is for expressing the trucks which is waiting to move in right side of the bridge
int bridge[102];
int bridge_begin, bridge_end;
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int tmp;

	input_faster();
	std::cin >> n >> w >> L;
	bridge_begin = 1;
	bridge_end = w;
	for (int i = 0 ; i < n ; i++)
	{
		std::cin >> tmp;
		q.push(tmp);
	}
	ans = 0;
}

int bridge_state() // calculating the number of trucks
{
	int cnt = 0;

	for (int i = bridge_begin ; i <= bridge_end ; i++)
		if (bridge[i])
			cnt++;
	return (cnt);
}

void bridge_move() // move the trucks right to left in the bridge
{
	for (int i = bridge_begin ; i <= bridge_end + 1 ; i++)//bridge_end + 1 is for begin_end to 0
		bridge[i - 1] = bridge[i];
}

int bridge_weight() // calculateing trucks weight above the bridge
{
	int weight = 0;

	for (int i = bridge_begin ; i <= bridge_end ; i++)
		weight += bridge[i];
	return (weight);
}

void move_action() // move control both bridge and queue
{
	int top, weight;

	bridge_move();
	top = q.front();
	weight = bridge_weight();
	if (!q.empty() && weight + top <= L && !bridge[bridge_end]) // when truck can move in right side, and the birdge of the end side is clear
	{
		q.pop();
		bridge[bridge_end] = top;
	}
}

void solve()
{
	while (!q.empty() || bridge_state()) //when q is not empty, or the bridge is not clear
	{
		move_action();
		ans++;
	}
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

