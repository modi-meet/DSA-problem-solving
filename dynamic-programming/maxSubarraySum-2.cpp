// Maximum subarray sum with only one deletion allowed

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
 
  vector<int> arr(n);
  int total = 0;
  for(auto &x : arr) {
    cin >> x;
    total += x;
  }
 
  // find min subarray sum
  // possibly zero

  // normal kadane (max subarray sum)
  int maxSum = arr[0];
  int prev = arr[0];
  for(int i=1; i<n; i++) {
    prev = max(prev+arr[i], arr[i]);
    maxSum = max(maxSum, prev);
  }
 
  // minSum Kadane (min subarray sum)
   prev = arr[0];
   int minSum = arr[0];
  for(int i=1; i<n; i++) {
    prev = min(prev+arr[i], arr[i]);
   
    minSum = min(minSum, prev);
  }
 
 
  if(maxSum < 0) cout << maxSum;
  else cout << max(maxSum, total - minSum);
 

  return 0;

}

/*
Approach 1 : append the same array to end
- 1 2 3 4 5, 5 4 3 2 1

Approach 2 : twice Kadane
