//2842
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

char town[53][53];
int altitude[53][53];
int alt_for_cal[2501];
bool visited[53][53];
std::string inp[51];
int highest, lowest;
int post_i, post_j;
int N;
int K;
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}; // 오른쪽 부터 시계방향
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int tire;
int ans;
int alt_length;
int dfs_K;

void dfs(int x, int y, int low, int high)
{

	if (!dfs_K|| altitude[x][y] < low || altitude[x][y] > high || town[x][y]== 'x' || visited[x][y])
		return ;
	if (town[x][y] == 'K')
		dfs_K--;

	visited[x][y] = 1;
	for(int i = 0 ; i < 8 ; i++)
	{
		if (!dfs_K)
			return;
		dfs(x + dx[i], y + dy[i], low, high);
	}
}

void binary_search()
{
	int low = 0;
	int high = 0;
	ans = 1000001;
	while (high < alt_length)
	{
		memset(visited, 0, sizeof(visited));
		dfs_K = K;
		dfs(post_i, post_j, alt_for_cal[low], alt_for_cal[high]);
		if (!dfs_K)
		{
			if (ans > alt_for_cal[high] - alt_for_cal[low])
				ans = alt_for_cal[high] - alt_for_cal[low];
			low++;
		}
		else
			high++;
	}
}

void input()
{
	std::cin >> N;
	K = 0;
	for(int i = 0 ; i < N ; i++)
		std::cin >> inp[i];
	memset(town, 'x', sizeof(town)); // town 초기화
	for(int i = 1 ; i <= N ; i++)
		for(int j = 1 ; j <= N ; j++)
		{
			town[i][j] = inp[i - 1][j - 1];
			if (town[i][j] == 'P') // 우체국 시작 위치
			{
				post_i = i;
				post_j = j;
			}
			if (town[i][j] == 'K') // K 갯수 세기. K를 모두 찾은 경우 피로도는 보장.(왔던길 그대로 돌아오면 되므로)
				K++;
		}
	int index = 0;
	for(int i = 1 ; i <= N ; i++)
		for(int j = 1 ; j <= N ; j++)
		{
			std::cin >> altitude[i][j];
			alt_for_cal[index++] = altitude[i][j];
		}
	std::sort(alt_for_cal , alt_for_cal + index);
	alt_length = 1;
	for(int i = 1 ; i < index; i++)
		if(alt_for_cal[i] != alt_for_cal[i - 1])
			alt_for_cal[alt_length++] = alt_for_cal[i];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	input();
	binary_search();
	std::cout << ans;
	return (0);
}
