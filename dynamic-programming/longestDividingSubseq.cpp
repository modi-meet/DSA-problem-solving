// Longest Dividing Subsequence
// Find longest subsequence where arr[i] is divisible by arr[i-1]

#include <bits/stdc++.h>
using namespace std;

int n;

int solve(int i, int prev, vector<int>& arr) {
  if (i == n) return 0;
 
  // skip
  int skip = solve(i + 1, prev, arr);

  // take
  int take = 0;
  if (prev == -1 || arr[i] % arr[prev] == 0) {
      take = 1 + solve(i + 1, i, arr);
  }

  return max(skip, take);
}

int main() {
  cin >> n;
 
  vector<int>arr(n);
  for(auto &x : arr) cin >> x;
 
  cout << solve(0, 0, arr);
 
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int longest = *max_element(dp.begin(), dp.end());
    cout << longest;

    return 0;
}