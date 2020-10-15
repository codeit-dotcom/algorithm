#include <iostream>

int get_change(int m) {
  int n;
  int p=m;

  n=m/4;
  m=m%4;
  n+=m/3;
  m=m%3;
  n+=m;
  if(p%3==0){
    if(n>p/3) {return p/3;}
    
  }
   
    

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
