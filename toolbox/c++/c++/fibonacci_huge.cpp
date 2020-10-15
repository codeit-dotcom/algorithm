#include <iostream>
#include<cmath>

/*long long get_fibonacci_huge_naive(long long n, long long m) {
    long long j;
    long long pre=0,curr=1;
    long long x=pow(m,2);
    for( j=0;j<x;++j){
        long long temp=pre;
        pre=curr;
        curr=(temp+curr)%m;
        if(pre==0&&curr==1){
            j=j+1;
            break;

        }


    }

    n=n%j;
    long long num[n+1];
    num[0]=0;
    num[1]=1;
    for(int i=2;i<=n;++i){
        num[i]=num[i-1]+num[i-2];
    }
    return num[n]%m;
}*/
long long pisano(long long m){
    long long a=0, b=1,c=a+b;
    long long x=pow(m,2);
    int j;
    for(  j=0;j<x;++j){
        c=(a+b)%m;
        a=b;
        b=c;
        if(a==0&&b==1)
            break;
    }return j+1;
}
long long get_fibonacci_huge_naive(long long n, long long m) {
    n=n%pisano(m);
    long long num[n+1];
    num[0]=0;
    num[1]=1;
    for(int i=2;i<=n;++i){
        num[i]=num[i-1]+num[i-2];
    }
   
   
   return num[n]%m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
