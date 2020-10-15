#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
#include<cstring>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp){
int n=(exp.size()+1)/2;
long long minv[n][n];
long long maxv[n][n];
memset(minv,0,sizeof(minv));
memset(maxv,0,sizeof(maxv));
 for(int i=0;i<n;i++){
   maxv[i][i]=std::stoll(exp.substr(2*i,1));
   minv[i][i]=std::stoll(exp.substr(2*i,1));
 }
 for (int s = 0; s < n- 1; s++)
  {
	  for (int i = 0; i < n - s - 1; i++)
	  {
		  int j = i + s + 1;
		  long long minVal = LLONG_MAX;
	      long long maxVal = LLONG_MIN;
	      // find the minimum and maximum values for the expression
	      // between the ith number and jth number
		  for (int k = i; k < j; k++ )
	      {
			  long long a = eval(minv[i][k],minv[k + 1][j],exp[2 * k + 1]);
			  long long b = eval(minv[i][k],maxv[k + 1][j],exp[2 * k + 1]);
			  long long c = eval(maxv[i][k],minv[k + 1][j],exp[2 * k + 1]);
			  long long d = eval(maxv[i][k],maxv[k + 1][j],exp[2 * k + 1]);
			  minVal = min(minVal,min(a,min(b,min(c,d))));
			  maxVal = max(maxVal,max(a,max(b,max(c,d))));
	      }
		  minv[i][j] = minVal;
		  maxv[i][j] = maxVal;
	  }
  }

  return maxv[0][n - 1];

}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
