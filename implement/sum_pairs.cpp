//13900
#include <iostream>
#include <vector>
typedef long long ll;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int N;
	ll ans;
	std::cin >> N;
	std::vector <ll> vec;
	vec.resize(N);
	for (size_t i = 0; i < N ; i++)
		std::cin >> vec[i];
	ans = 0;
	for (size_t i = 0; i < N; i++)
		ans += vec[i];
	ans *= ans;
	for (size_t i = 0 ; i < N ; i++)
		ans -= (vec[i] * vec[i]);
	printf("%lld", ans / 2);

	return (0);
}
