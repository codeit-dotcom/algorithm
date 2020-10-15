#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    int num[n+1];
    num[0]=0;
    num[1]=1;
    for(int i=2;i<=n;++i){
        num[i]=(num[i-1]+num[i-2])%10;
    }
return num[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
