// Longest Increasing Substring
// A substring is a contiguous non-empty sequence of characters within a string.

class Solution {
    int n1, n2;
    int t[1002][1002];
    
private:
    int solve(string& s1, string& s2, int idx1, int idx2){
        if(idx1 == n1 || idx2 == n2) return 0;
        
        if(t[idx1][idx2] != -1) return t[idx1][idx2];
        
        if(s1[idx1] == s2[idx2]) {
            return t[idx1][idx2] = 1 + solve(s1, s2, idx1+1, idx2+1); // same character
        }
        else { // subseq is broken; start new one
            return t[idx1][idx2] = 0;
        }
    }
    
public:
    int longestCommonSubstr(string& s1, string& s2) {
        n1 = s1.length(), n2 = s2.length();
        int maxLen = 0;
        
        memset(t, -1, sizeof(t));
        
        // return solve(s1, s2, 0, 0); FAILS -> this only gives result for starting at 0
        
        // for all starting points
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                maxLen = max(maxLen, solve(s1, s2, i, j));
            }
        }
        
        return maxLen;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// Tabulation
class Solution {
public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.length(), m = s2.length();
        int maxLen = 0;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                    maxLen = max(maxLen, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return maxLen;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)