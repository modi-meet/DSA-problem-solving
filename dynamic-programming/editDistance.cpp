// Edit Distance
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// three operations permitted on a word:
//  - Insert a character
//  - Delete a character
//  - Replace a character

// Recursion + Memoized Approach
class Solution {
    int t[502][502];
private:
    int solve(string s1, string s2, int i, int j){
        if(i == s1.length()) return s2.length() - j;
        if(j == s2.length()) return s1.length() - i;

        if(t[i][j] != -1) return t[i][j];

        // same
        if(s1[i] == s2[j]) return solve(s1, s2, i+1, j+1);

        // different; do the operations
        int insert = 1 + solve(s1, s2, i+1, j);
        int del = 1 + solve(s1, s2, i, j+1);
        int replace = 1 + solve(s1, s2, i+1, j+1);

        return t[i][j] = min({insert, del, replace});
    }

public:
    int minDistance(string word1, string word2) {
        memset(t, -1, sizeof(t));

        return solve(word1, word2, 0, 0);
    }
};
// TC : O(n*m)
// SC: O(n*m)

// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2){
        int n = word1.length(), m = word2.length();
        // if(word1 == word2) return 0;
        if(n == 0) return m;
        if(m == 0) return n;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) { // same
                    dp[i][j] = dp[i-1][j-1];
                } else { // not same; do the operations
                    int insert = 1 + dp[i-1][j];
                    int del = 1 + dp[i][j-1];
                    int replace = 1 + dp[i-1][j-1];
                    
                    dp[i][j] = min(min(insert, del), replace);
                }
            }
        }

        return dp[n][m];
    }
};
// TC : O(n*m)
// SC: O(n*m)
