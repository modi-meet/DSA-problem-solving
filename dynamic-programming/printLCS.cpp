// Print LCS
// Given two strings, print the longest common subsequence.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    
    void buildLCSTable(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } 
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    
public:
    string printLCS(string s1, string s2) {
        buildLCSTable(s1, s2);
        
        string ans = "";
        int n = s1.length(), m = s2.length();
        int i = n, j = m;
        
        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {           
                ans = s1[i-1] + ans;        
                i--; 
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        
        return ans; 
    }
};

int main() {
    Solution sol;
    
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    
    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    
    string result = sol.printLCS(s1, s2);
    cout << "LCS: " << result << endl;
    cout << "Length: " << result.length() << endl;
    
    return 0;
}

/*
OUTPUT:
String 1: ABCDGH
String 2: AEDFHR
LCS: ADH
Length: 3
*/