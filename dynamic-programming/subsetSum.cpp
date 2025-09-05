// Given an array of positive integers and a value, determine if there is a subset of array with sum equal to given sum. 

// Recursion + memoized Approach
class Solution {
    int n;
    int t[10002][202];
    
  private:
    bool solve(vector<int>& arr, int rem, int idx){
        if(rem == 0) return true;
        if(rem < 0 || idx == n) return false;
        
        if(idx == n) return false;
        
        if(t[rem][idx] != -1) return t[rem][idx];
        
        if(arr[idx] <= rem) {
            return t[rem][idx] = (solve(arr, rem - arr[idx], idx+1) || solve(arr, rem, idx+1));
        } else {
            return t[rem][idx] = solve(arr, rem, idx+1);
        }
    }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        n = arr.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(arr, sum, 0);
    }
};
// Only Recursion : TC - O(2^n)

// Time Complexity: O(n*m)
// Space Complexit: O(n*m)

// Tabulation
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        for(int j=1; j <= sum; j++){
            dp[0][j] = false; 
            // arr size = 0, sum = 1,2,3...1001 (0size array cannot make >1 sum; not possible) 
        }
        
        for(int i=0; i <= n; i++){
            dp[i][0] = true;
            // arr size = 0,1,2,3...200, sum = 0 always possible; empty subset, don't include any element
        }
        
        for(int i=1; i <= n; i++){
            for(int j=1; j <= sum; j++){
                if(arr[i-1] <= j) { // if we include the element and that is less than sum, then:
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                } else { // otherwise
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
// Time Complexity: O(n*m)
// Space Complexit: O(n*m)