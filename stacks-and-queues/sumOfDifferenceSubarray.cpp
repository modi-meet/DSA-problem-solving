// Find the sum of difference b/w maximum and minimum element in all the subarray


#include <bits/stdc++.h>
using namespace std;

int n;

long long sumMax(vector<int>& arr) {
  stack<int> st;
  
  vector<int> left(n);  
  for(int i=0; i<n; i++) {
    while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
    
    left[i] = st.empty() ? i+1 : i-st.top();
    st.push(i);
  }
  
   while(!st.empty()) st.pop();
  
  vector<int> right(n);
  for(int i=n-1; i>=0; i--) {
    while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
    
    right[i] = st.empty() ? n-i : st.top()-i;
    st.push(i);
  }
  
  long long ans = 0;
  for(int i=0; i<n; i++) {
    ans = (ans + 1LL*arr[i]*left[i]*right[i]);
  }
  
  return ans;
}


long long sumMin(vector<int>& arr) {
  stack<int> st;
  
  vector<int> left(n);  
  for(int i=0; i<n; i++) {
    while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
    
    left[i] = st.empty() ? i+1 : i-st.top();
    st.push(i);
  }
  
   while(!st.empty()) st.pop();
  
  vector<int> right(n);
  for(int i=n-1; i>=0; i--) {
    while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    
    right[i] = st.empty() ? n-i : st.top()-i;
    st.push(i);
  }
  
  long long ans = 0;
  for(int i=0; i<n; i++) {
    ans = (ans + 1LL*arr[i]*left[i]*right[i]);
  }
  
  return ans;
}


int main() {
  cin >> n;
  
  vector<int> arr(n);
  for(auto &x : arr) cin >> x;
  
  long long ans = (sumMax(arr) - sumMin(arr));
  cout << ans;
  
  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)