#include <string>
#include <vector>


void recursion(int n, std::string &answer, char _flip[])
{
    int quo, rem;
    
    quo = n / 3;
    rem = n % 3;
    
    if (!rem)
            quo--;
    if (quo >= 1)
        recursion(quo, answer, _flip);
    answer += _flip[rem];
}

std::string solution(int n) {
    
    char _filp[4] = {'4', '1', '2'};
    std::string answer = "";
    recursion(n, answer, _filp);
    return answer;
}
