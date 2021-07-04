#include <string>
#include <vector>
#include <cmath>

long long max_val;

long long cal_val(long long a, long long b, char op)
{
    if (op == '+')
        return (a + b);
    else if (op == '-')
        return (a - b);
    else
        return (a * b);
}

void find_max_val(std::vector<long long> num, std::vector<char> op, std::vector<char> total_op, int visited)
{
    long long tmp;
    
    if (op.size() == 0)
    {
        std::cout << num[0] << std::endl;
        if (max_val < std::abs(num[0]))
            max_val = std::abs(num[0]);
        return ;
    }
    int num_point = 0;

    for (int i = 0 ; i < 3 ; i++)
    {
        std::vector<long long> new_num;
        std::vector<char> new_op;
        if (visited == (visited | (1 << i)))
            continue;
        new_num.push_back(num[0]);
        for (size_t j = 1 ; j < num.size(); j++)
        {
            if (op[j - 1] == total_op[i])
            {
                tmp = new_num.back();
                new_num.pop_back();
                tmp = cal_val(tmp, num[j], op[j - 1]);
                new_num.push_back(tmp);
            }
            else
            {
                new_num.push_back(num[j]);
                new_op.push_back(op[j - 1]);
            }
        }
        find_max_val(new_num, new_op, total_op, visited | (1 << i));
    }
}
    
long long solution(std::string expression) {
    long long answer = 0;
    max_val = 0;
    std::vector<long long> num;
    std::vector<char> op;
    std::vector<char> total_op = {'-','+','*'};
    int i = -1;
    long long tmp = 0;
    int e_len = expression.size();
    while (++i < e_len)
    {
        if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*')
        {
            op.push_back(expression[i]);
            num.push_back(tmp);
            tmp = 0;
        }
        else
        {
            tmp = tmp * 10 + expression[i] - '0';
            if (i == e_len - 1)
                num.push_back(tmp);
        }
    }
    find_max_val(num, op, total_op, 0); // 숫자들 벡터, 연산자 벡터, 모든 연산자, visited
    answer = max_val;
    return answer;
}
