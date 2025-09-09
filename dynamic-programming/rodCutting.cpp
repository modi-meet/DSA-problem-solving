// Rod Cutting

class Solution {
    int n;
    int t[1002][1002];
    
  private:
    int solve(vector<int> &price, int idx, int remLen){
        if(idx >= n || remLen <= 0) return 0;
        
        if(t[idx][remLen] != -1) return t[idx][remLen];
        
        int pieceLen = idx+1; // size of the piece
        
        int take = 0;
        if(pieceLen <= remLen){
            take = price[idx] + solve(price, idx, remLen - pieceLen);
        }
        
        int notTake = solve(price, idx+1, remLen);
        
        
        return t[idx][remLen] = max(take, notTake);
    }
  public:
    int cutRod(vector<int> &price) {
        n = price.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(price, 0, n);
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Tabulation
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for (int pieceLen = 1; pieceLen <= n; pieceLen++) {
            for (int rodLen = 1; rodLen <= n; rodLen++) {
                if(pieceLen <= rodLen){
                    dp[pieceLen][rodLen] = max(price[pieceLen-1] + dp[pieceLen][rodLen - (pieceLen-1 +1)], dp[pieceLen-1][rodLen]);
                }
                else dp[pieceLen][rodLen] = dp[pieceLen-1][rodLen];
            }
        }
        
        return dp[n][n];
        
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)