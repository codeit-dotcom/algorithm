
/*#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
  int maxHeight = 0;
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
  }
    
  std::cout << maxHeight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}*/
#include<bits/stdc++.h>
using namespace std;
int root=0;
int main()
{
  int n;
  cin>>n;
  vector< vector<int> >nodes(n);
  queue<int>q;
  int a[n];
  for(int i=0;i<n;i++)
  {
	  cin>>a[i];
	  if(a[i]==-1)root=i;
	  else {
		  nodes[a[i]].push_back(i);
	  }
  }
  q.push(root);
  int height=0;
  while(true)
  {
	  int nodecount=q.size();
	  if(nodecount==0){
		  cout<<height<<endl;
		  return 0;
	  }
	  height+=1;
	  while(nodecount>0){
		  int node=q.front();
		  q.pop();
		  if(!nodes[node].empty()){
			  for(int i=0;i<nodes[node].size();i++)
				  q.push(nodes[node][i]);
		  }
		  nodecount--;
	  }
  }
    return 0;
}
