#include <iostream>

int gcd_naive(int a, int b) {
  long long high,low,rem;
  high=a>=b?a:b;
  low=a>=b?b:a;
  do{
    rem=high%low;
    high=low;
    low=rem;

  }while(rem!=0);
  return high;
}
int main(){
  long long a ,b;
  std::cin>>a>>b;
  std::cout<<gcd_naive(a,b);
  return 0;
}