// Longest Common Subsequence length
// A common subsequence of two strings is a subsequence that is common to both strings. (subseq - without changing the relative order of the remaining characters)

// Recursion + memoized Approach
class Solution {
    int n1, n2;
    int t[1002][1002];

private:
    int solve(string& text1, string& text2, int idx1, int idx2){
        if(idx1 == n1 || idx2 == n2) return 0;

        if(t[idx1][idx2] != -1) return t[idx1][idx2];

        if(text1[idx1] == text2[idx2]) {
            return t[idx1][idx2] = 1 + solve(text1, text2, idx1+1, idx2+1); // one character found to be a common subseq
        }
        else {
            int moveFirst = solve(text1, text2, idx1+1, idx2);
            int moveSecond = solve(text1, text2, idx1, idx2+1);

            return t[idx1][idx2] = max(moveFirst, moveSecond);
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.length(), n2 = text2.length();

        memset(t, -1, sizeof(t));

        return solve(text1, text2, 0, 0);
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// Tabulation
class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        int n = text1.size(), m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    int moveFirst = dp[i-1][j];
                    int moveSecond = dp[i][j-1];
                    
                    dp[i][j] = max(moveFirst, moveSecond);
                }
            }
        }
        return dp[n][m];
        
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)