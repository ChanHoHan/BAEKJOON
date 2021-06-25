#include <cmath>

long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    long long val = 0;
    int a, b;
    double d_w = w, d_h = h;
    
    for (int i = 0 ; i < h ; i++)
    {
        a = std::ceil((-d_w * i + d_w * d_h) / d_h);
        b = (int)((-d_w * (i + 1) + d_w * d_h) / d_h);
        val += (a - b);
    }
    answer -= val;
    
    return answer;
}
