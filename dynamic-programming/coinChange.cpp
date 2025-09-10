// Coin Change (Minimum Coin)
// Task is to determine the minimum number of coins needed to obtain the target sum.
// If it is not possible to form the sum using the given coins, return -1.

// Recursion + memoized Approach
class Solution {
    int n;
    
private:
    int solve(vector<int> &coins, int rem, int idx){
        if(rem == 0) return 0;
        if(idx >= n) return INT_MAX;
        
        int take = INT_MAX;
        if(coins[idx] <= rem) {
            int result = solve(coins, rem - coins[idx], idx);
            
            if(result != INT_MAX) take = 1 + result; // take the coin
        }
        
        int notTake = solve(coins, rem, idx+1);
        
        return min(take, notTake);
    }
        
public:
    int minCoins(vector<int> &coins, int sum) {
        n = coins.size();
        
        
        int ans = solve(coins, sum, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};


class Solution{
public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        
        vector<vector<int>> dp(n+1, vector<int> (sum+1, INT_MAX));
        for(int i=0; i<=n; i++) dp[i][0] = 0;
     
        for(int i=1; i<=n; i++){
            for(int j=1; j <= sum ;j++){
                
                dp[i][j] = dp[i-1][j];
                
                if(coins[i-1] <= j) {
                    int res = dp[i][j - coins[i-1]];
                    
                    if(res != INT_MAX){
                        dp[i][j] = min(1 + res, dp[i][j]);
                    }
                }
                
                
            }
        }
        
        return dp[n][sum] == INT_MAX ? -1 : dp[n][sum];
    }
};