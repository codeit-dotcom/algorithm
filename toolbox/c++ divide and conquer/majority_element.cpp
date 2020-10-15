#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// this algorithm i summited in my course
/*
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  sort(a.begin(),a.end());
  int mid= left + (right-left)/2;
  int maxrepeat=a[mid];
  int count =0;
  for(int i=0;i<a.size();i++){
    if(a[i]==maxrepeat)
      count++;
  }
if(count>a.size()/2){
   return 0;}

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1)<< '\n';
}*/
//this is practise work..hope it works
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return 0;
  if (left + 1 == right) return 1;
  sort(a.begin(),a.end());
  
  int n=a.size()/2;
  if(a[n]==a[0])
      return 1;
 else if(a[right-n]==a[right])
       return 1;   
else 
     return 0;     
}       
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size()-1)<< '\n';
}