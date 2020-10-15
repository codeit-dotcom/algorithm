#include <iostream>

/*int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    int num[n+1];
    num[0]=0;
    num[1]=1;
long long sum =1;

    for (long long i = 2; i <=n; ++i) {
        num[i]=(num[i-2]+num[i-1])%10;
        sum=sum+num[i];

    }

    return sum % 10;
}*/
int  fibno(int n,long long m){
    int fib[n+1];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++){
        fib[i]=(fib[i-1]+fib[i-2])%m;

    }
    
   return fib[n]; 
}
int pisano(long long m){
    if(m==1){
        return 0;
    }
 int first=-1;
 int second=-1;
 int i=2;
 while(1){
     second=fibno(i,m);
     if(second==1 && first==0){
         return i-1;
     }first=second;
      i=i+1;
 }
}



int fibohuge(long long n,long long m){
    int t=pisano(m);
    int s=n%t;
    return fibno(s,m);
    
}
int sumfib(long n){
    return (fibohuge(n+2,10)-1)%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    int sum = sumfib(n);
    int value = sum < 0 ? (sum + 10) : sum;
    std::cout << value;
}
