#include <iostream>
#include <vector>
#include <algorithm>


using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  vector <int> result;
public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }
  void  inOrder(int index){
    if(left[index]!= -1)
              inOrder(left[index]);
    result.push_back(key[index]);
      if(right[index]!=-1){
            inOrder(right[index]);
      }          
  }

  vector <int> in_order() {
    result.clear();
    inOrder(0);

    return result;
  }
  void preOrder(int index){
     result.push_back(key[index]);
     if(left[index] != -1)
        
       preOrder(left[index]);
     
       if(right[index] != -1)  
          preOrder(right[index]);

     
  }

  vector <int> pre_order() {
   result.clear();
   preOrder(0);
    return result;
  }
 void postOrder(int index){
   if(left[index]!= -1)
            postOrder(left[index]);
    if(right[index] != -1)
         postOrder(right[index]);
   result.push_back(key[index]);                
 }
  vector <int> post_order() {
    result.clear();
    postOrder(0);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}



