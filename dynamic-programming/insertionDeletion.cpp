class Solution {
  public:
    int minOperations(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        int LCS = dp[n][m];
        
        int deletion = n-LCS;
        int insertion = m-LCS;
        
        return insertion + deletion;
    }
};