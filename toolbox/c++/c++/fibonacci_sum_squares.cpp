#include <iostream>
#include<cmath>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

n=n%60;
    int num[n+1];
    num[0]=0;
    num[1]=1;
long long sum =1;
    for (long long i = 2; i <=n; ++i) {
        num[i]=(num[i-2]+num[i-1]);
        
        }
    return num[n]%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    long long a=fibonacci_sum_squares_naive(n);
    long long b=fibonacci_sum_squares_naive(n+1);
    std::cout << (a*b)%10;
}
