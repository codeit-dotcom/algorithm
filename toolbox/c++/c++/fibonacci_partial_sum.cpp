#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if(to==2)
    return 2;

    int num[to+1];
    num[0]=0;
    num[1]=1;
long long sum =0;
    for (long long i = 2; i <=to; ++i) {
        num[i]=(num[i-2]+num[i-1])%10;
        if(i>=from){
            sum=sum+num[i];
        }
        


    }return sum%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
