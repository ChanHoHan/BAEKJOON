#include <iostream>
#include <string>
#include <cmath>
typedef long long ll;
int main()
{
	std::string N;
	ll len, first, val;
	ll ans;
	std::cin >>  N;
	ans = 0;
	len = N.size();

	first = std::pow(10, len - 1);
	val = std::stoi(N);
	ans += len * (val - first + 1);
	for (int i = len - 1 ; i > 0 ; i--)
		ans += 9* i * std::pow(10, i - 1);
	if (val <= 9)
		ans = val;
	printf("%lld", ans);
	return (0);
}
