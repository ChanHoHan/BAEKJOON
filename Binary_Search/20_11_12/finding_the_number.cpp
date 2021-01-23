#include <iostream>
#include <algorithm>
#define endl "\n"

void is_member(int *A, int *member_possible, int N, int M)
{
	for (int i = 0 ; i < M ; i++)
	{
		if (std::binary_search(A, A+N, member_possible[i]))
			std::cout << 1 << endl;
		else
			std::cout << 0 << endl;
	}
}
			
int *make_array(int n)
{
	int *arr = new int[n];
	for(int i = 0 ; i < n; i++)
		std::cin >> arr[i];
	return (arr);
}

void free_array(int *A, int *B)
{
	delete(A);
	delete(B);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int N;
	int M;
	
	std::cin >> N;
	int *A = make_array(N);
	std::sort(A, A+N); //바이너리 서치를 위한 소팅
	std::cin >> M;
	int *member_possible = make_array(M);
	is_member(A, member_possible, N, M);
	free_array(A, member_possible);

	return 0;
}
