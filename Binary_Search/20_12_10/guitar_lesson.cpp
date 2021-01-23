#include <iostream>
#include <vector>

int M, MAX, ans;
size_t N;
std::vector <int> guitar;

int cal(int &mid)
{
	int tmp, cal_val;
    
	tmp = 0;
	cal_val = 0;
	for (size_t i = 0 ; i < N ; i++)
	{
		if (mid < guitar[i])  // 이유 : 레슨 길이가 블루레이 크기보다 크면 안되기 때문
			return (0);
		tmp += guitar[i];
		if (tmp > mid)
		{
			tmp = 0;
			tmp += guitar[i];
			cal_val++;
		}
		if (i == N - 1)
			cal_val++;
	}

	if (cal_val <= M)
		return (1);
	else
		return (0);
}

void binary_search(int min, int max)
{
	if (min > max)
		return ;
	int mid = (min + max) / 2;
	if (cal(mid))
	{
		ans = mid;
		binary_search(min, mid - 1);
	}
	else
		binary_search(mid + 1, max);
}



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N >> M;
	guitar.resize(N);
	for(size_t i = 0 ; i < N ; i++)
		std::cin >> guitar[i];
	MAX = 10000 * static_cast<int>(N);
	ans = 0;
	binary_search(1, MAX);
	printf("%d", ans);
	return(0);
}
