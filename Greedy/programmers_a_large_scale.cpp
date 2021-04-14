//https://programmers.co.kr/learn/courses/30/lessons/42883
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool com_val(std::pair<char, int> a , std::pair<char, int> b)
{
	if (a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}

string solution(string number, int k) {
	string answer = "";
	int N = number.size();
	int x;

	pair<char, int> num[N];
	for (int i = 0 ; i < N; i++)
	{
		num[i].first = number[i];
		num[i].second = i;
	}
	sort(num, num + N, com_val);
	for (int i = 0 ; i < N ; i++)
		cout << num[i].first;
	cout << "\n";

	for (int i = 0 ; i < N ; i++)
	{
		if (answer > 
	}
	
	return answer;
}

int main()
{
	cout << solution("4177252841", 4);
}
