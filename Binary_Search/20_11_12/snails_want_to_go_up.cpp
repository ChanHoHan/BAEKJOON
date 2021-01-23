#include <iostream>

int main()
{
	int A,B,V;
	std::cin >> A >> B >> V;

	int certain_days; // 확정적인 날짜
	int calculate_days; // 정확히 구해야 하는 날짜
	int distance = 0;

	certain_days = (V - A) / (A - B);
	calculate_days = V - (certain_days * (A - B));

	if (calculate_days)
	{
		while(true)
		{
			certain_days+=1;
			distance += A;
			if (distance >= calculate_days)
				break;
			distance -= B;
		}
	}
	std::cout << certain_days;

	return (0);
}

