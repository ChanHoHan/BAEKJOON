//10101 브론즈
#include <iostream>
#include <string>
int main()
{
	int a,b,c;
	std::string rtn;

	std::cin >> a >> b >> c;
	
	if (a+b+c != 180)
	{
		std::cout << "Error";
		return (0);
	}
	if (a == b && b == c)
		rtn = "Equilateral";
	else if (a != b && b != c && a != c)
		rtn = "Scalene";
	else
		rtn = "Isosceles";
	std::cout << rtn;

	return (0);
}
