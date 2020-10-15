#include <iostream>
/*int gcd_naive(int a, int b) {
  if(a<b){
      int s=b;
      b=a;
      a=s;
  }
    
      if(a%b==0){ return b;}
      else {return gcd_naive(b,a%b);}
    
 
}

long long lcm_naive(int a, int b) {
  return (a*b)/gcd_naive(a,b);
}*/
long long lcm_naive(int a, int b) {
    long long m,n;
    m=a;
    n=b;
    while(m!=n){
      if(m<n){
        m=m+a;
      }else{
        n=n+b;
      }
    }
return m;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
