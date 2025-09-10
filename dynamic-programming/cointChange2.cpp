// Coin Change 2
// Given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// Recursion + memoized Approach
class Solution {
    int n;
    int t[302][5002];

private:
    int solve(int rem, vector<int>& coins, int idx){
        if(rem == 0) return 1;

        if(idx >= n) return 0;

        if(t[idx][rem] != -1) return t[idx][rem];

        int take = 0;
        if(coins[idx] <= rem) {
            take = solve(rem - coins[idx], coins, idx);
        }

        int notTake = solve(rem, coins, idx+1);

        return t[idx][rem] = take + notTake;
    }   

public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();

        memset(t, -1, sizeof(t));
        return solve(amount, coins, 0);
    }
};
// TC: O(n*amount)
// SC: O(n*amount)

// Tabulation
class Solution{
    public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;  
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1] <= j) {
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount];
    }
};
// TC: O(n*amount)
// SC: O(n*amount) (can be 1D DP - O(amount))