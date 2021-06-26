#include <string>
#include <vector>
#include <iostream>

void recursion(std::vector<int>& numbers, int index, int size, int target, int val, int &answer)
{   
    if (size <= index)
    {
        if (val == target)
            answer++;
        return;
    }
    recursion(numbers, index + 1, size, target, val + numbers[index], answer);
    recursion(numbers, index + 1, size, target, val - numbers[index], answer);
}

int solution(std::vector<int> numbers, int target) {
    int answer = 0;
    recursion(numbers, 0, numbers.size(), target, 0, answer);
    
    return answer;
}
