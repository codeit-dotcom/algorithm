#include <iostream>
#include <vector>
using std::vector;

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
int sumfib(long long from,long long to){
    return (fibohuge(to+2,10)-1)-(fibohuge(from+1,10)-1);
}


int main() {
    long long from, to;
    std::cin >> from >> to;
   int  x=sumfib(from, to) ;
    int value=x<0?x+10:x;
    std::cout<<value;
}
