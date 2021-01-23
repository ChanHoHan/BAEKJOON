// 2613
#include <iostream>
#include <vector>

int N, M;
std::vector <int> marble;
std::vector <int> ans_vec;
int ans, val_max;

bool cal(int mid, std::vector <int> &ans_save)
{
	size_t index = 0;
	int save_val = 0;
	int cnt = 0;
	val_max = 0;
	while(index < marble.size())
	{
		save_val += marble[index];
		cnt++;
		if (save_val > mid || ans_save.size() + (marble.size() - index + 1)
				<= M)
		{
			if (val_max < save_val - marble[index])
				val_max = save_val - marble[index];
			cnt--;
			if(cnt == 0)
				return (0);
			ans_save.push_back(cnt);
			save_val = marble[index];
			cnt = 1;
		}
		if (index == marble.size() - 1)
		{
			ans_save.push_back(cnt);
			if (val_max < save_val)
				val_max = save_val;
		}
		index++;
	}
	if (ans_save.size() <= static_cast<size_t>(M))
		return (1);
	return (0);
}


void binary_search(int min, int max)
{
	if (min > max)
		return ;
	int mid = (min + max) / 2;
	std::vector <int> ans_save;
	if(cal(mid, ans_save))
	{
		if (ans_save.size() == static_cast<size_t>(M) && ans >= val_max)
		{
			ans = val_max;
			for(size_t i = 0 ; i < static_cast<size_t>(M); i++)
				ans_vec[i] = ans_save[i];
		}
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
	marble.resize(N);
	ans_vec.resize(M);
	int sum_val = 0;
	for(size_t i = 0 ; i < static_cast<size_t>(N) ; i++)
	{
		std::cin >> marble[i];
		sum_val += marble[i];
	}
	ans = 300002;
	binary_search(1, sum_val);
	std::cout << ans << std::endl;
	for(size_t i = 0 ; i < static_cast<size_t>(M) ; i++)
		std::cout << ans_vec[i] << " ";
	
	return(0);
}
