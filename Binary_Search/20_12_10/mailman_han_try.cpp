//2842
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

char town[53][53];
int altitude[53][53];
int alt_for_cal[2501];
bool visited[53][53];
std::string inp[51];
int highest, lowest;
int post_i, post_j;
int N, K;
int dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1}; // 오른쪽 부터 시계방향
int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};
int tire;
int ans;
int k_lowest, k_highest;
int alt_length;
int dfs_K;

void dfs(int x, int y, int dfs_low, int dfs_high)
{

	if (!dfs_K || town[x][y] == 'x' || visited[x][y])
		return ;
	if (dfs_low > altitude[x][y])
		dfs_low = altitude[x][y];
	if (dfs_high < altitude[x][y])
		dfs_high = altitude[x][y];
	//std::cout << "k highest : " << k_highest << "k lowest : " << k_lowest <<std::endl;
	//std::cout << "altitude : " << altitude[x][y] << " where : " << town[x][y] << std::endl;
	if (tire < std::abs(k_highest - altitude[x][y]) || tire < std::abs(k_lowest - altitude[x][y]))
	{
		//std::cout << "in" << std::endl;
		return ;
	}
	if (dfs_high - dfs_low > tire)
		return ;

	visited[x][y] = 1;
	if (town[x][y] == 'K')
	{
		dfs_K--;
	}
	for(int i = 0 ; i < 8 ; i++)
	{
		if (!dfs_K)
			return;
		dfs(x + dx[i] , y + dy[i], dfs_low, dfs_high);
	}
	visited[x][y] = 0;
}

void binary_search(int min, int max)
{
	if (min > max)
		return ;
	int mid = (min + max) / 2;
	tire = mid;
	std::cout << "mid : " << mid  << std::endl;
	std::cout << "k_highest : " << k_highest << " k_lowest : " << k_lowest
		<< std::endl;
	memset(visited, 0, sizeof(visited));
	dfs_K = K;
	std::cout << " K : " << K << std::endl;
	dfs(post_i, post_j, 1000001, 0);
	if (!dfs_K)
	{
		if (ans > mid)
			ans = mid;
		binary_search(min , mid - 1);
	}
	else
		binary_search(mid + 1, max);
}

void cal_low_high(int index)
{
	int tmp;

	std::sort(alt_for_cal, alt_for_cal + index);
	highest = alt_for_cal[index - 1] - alt_for_cal[0];
	lowest = 1000001;
	int tmp_i = alt_for_cal[0];
	for(int i = 1 ; i < index ; i++)
	{
		if (tmp_i != alt_for_cal[i])
		{
			tmp = alt_for_cal[i] - tmp_i;
			tmp_i = alt_for_cal[i];
			if (tmp < lowest)
				lowest = tmp;
		}
	}
}

void input()
{
	std::cin >> N;
	K = 0;
	for(int i = 0 ; i < N ; i++)
		std::cin >> inp[i];
	memset(town, 'x', sizeof(town)); // town 초기화
	k_highest = 0;
	k_lowest = 1000001;
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
			
			if (town[i][j] == 'P' || town[i][j] == 'K')
			{
				if (k_highest < altitude[i][j])
					k_highest = altitude[i][j];
				if (k_lowest > altitude[i][j])
					k_lowest = altitude[i][j];
			}
		}
	/*
	std::sort(alt_for_cal , alt_for_cal + index);
	alt_length = 1;
	for(int i = 1 ; i < index; i++)
		if(alt_for_cal[i] != alt_for_cal[i - 1])
			alt_for_cal[alt_length++] = alt_for_cal[i];
			*/
	cal_low_high(index);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	input();
	ans = 1000001;
	binary_search(lowest, highest);
	std::cout << ans;
	return (0);
}
