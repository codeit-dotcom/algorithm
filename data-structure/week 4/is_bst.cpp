#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ios_base;

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
      if(right[index]!=-1)
            inOrder(right[index]);
               
  }

  bool in_order() {
    result.clear();
    inOrder(0);
   std::sort(key.begin(), key.end() );
  for(int i=0; i<n ; i++){
      if(result[i]!=key[i])
        return false;

  }
    
   return true;
  }
} ;
 int main() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  if (t.in_order()) {
    cout << "CORRECT" << endl;
  } 
  else {
    cout << "INCORRECT" << endl;
  }
  
  return 0;
} 
/* struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree) {
  
   

  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}*/
