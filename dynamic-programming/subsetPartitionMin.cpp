// Minimum sum partition
// Given an array, divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        
        int totalSum = 0;
        for(int num : arr) totalSum += num;
        
        // subset sum
        vector<vector<bool>> dp(n+1, vector<bool>(totalSum+1, false));
        
        for(int i=0; i<=n; i++) dp[i][0] = true; // initialization
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=totalSum; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                } 
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i=0; i<= totalSum/2; i++){
            int s2 = totalSum - i;
            int s1 = i;
            
            if(dp[n][i]) ans = min(ans, abs(s2 - s1));
        }
        
        return ans;
    }
};
// TC = O(n × totalSum)
// SC = O(n × totalSum)