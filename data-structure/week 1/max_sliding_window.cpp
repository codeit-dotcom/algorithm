/*#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}
*/
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find the maximum for each 
// and every contiguous subarray of size k 
void max_sliding_window_naive(vector<int> const & a, int k)
{ 
   int  n=a.size();
    // If k = 1, print all elements 
    if (k == 1) { 
        for (int i = 0; i < n; i += 1) 
            cout << a[i] << " "; 
        return; 
    } 
  
    // Using p and q as variable pointers 
    // where p iterates through the subarray 
    // and q marks end of the subarray. 
    int p = 0, 
        q = k - 1, 
        t = p, 
        max = a[k - 1]; 
  // Iterating through subarray. 
    while (q <= n - 1) { 
  
        // Finding max 
        // from the subarray. 
        if (a[p] > max) 
            max = a[p]; 
  
        p += 1; 
  
        // Printing max of subarray 
        // and shifting pointers 
        // to next index. 
        if (q == p && p != n) { 
            cout << max << " "; 
            q++; 
            p = ++t; 
  
            if (q < n) 
                max = a[q]; 
        } 
    } 
} 

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
