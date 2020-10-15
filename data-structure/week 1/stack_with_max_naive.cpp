#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;
using std::endl;

class StackWithMax {
    vector<int> stack;
    vector<int> maxe;

  public:

    void Push(int value) {
        if(stack.empty()){
            maxe.push_back(value);
            stack.push_back(value);
        }
        if(value>=maxe.back()){
          stack.push_back(value);
          maxe.push_back(value);
    } else { stack.push_back(value);}
    }
    void Pop() {
        assert(stack.size());
        
        if(maxe.back()==stack.back())
      { stack.pop_back();
        maxe.pop_back();
    } else 
        stack.pop_back();
    }
    int Max() const {
        assert(stack.size());
        return maxe.back();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;
    vector<int> s;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            s.push_back(stack.Max());
        }
        else {
            assert(0);
        }
    }
    int n=s.size();
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}