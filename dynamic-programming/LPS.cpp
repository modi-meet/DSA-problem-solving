// Longest Palindromic Subsequence
// Given string s, return LPS length.

class Solution {
public:
    int longestPalinSubseq(string &s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        
        int n = s1.length(), m = s2.length();
        
        // int lcs = LCS(s1, s2);
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int lcs = dp[n][m];
        
        
        return lcs;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)