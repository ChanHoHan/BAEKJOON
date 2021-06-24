#include <iostream>
#include <string>
#include <stack>

int solution(std::string s)
{
    int answer = 0;
    
    std::stack<int> st;
    for (size_t i = 0 ; i < s.size() ; i++)
    {
        if (st.empty())
            st.push(s[i]);
        else
        {
            if (st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }
    }
    if (st.empty())
        answer = 1;
    return answer;
}
