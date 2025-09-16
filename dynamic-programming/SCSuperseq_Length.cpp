// Shortest Common Supersequence
// Given two strings s1 and s2, find the length of the smallest string which has both s1 and s2 as its sub-sequences.

class Solution {
    int n, m;
    int t[502][502];
    
private:
    int LCS(string &s1, string &s2, int idx1, int idx2){
        if(idx1 == n || idx2 == m) return 0;
        
        if(t[idx1][idx2] != -1) return t[idx1][idx2];
        
        if(s1[idx1] == s2[idx2]) return t[idx1][idx2] = 1 + LCS(s1, s2, idx1+1, idx2+1);
        else{
            int moveFirst = LCS(s1, s2, idx1+1, idx2);
            int moveSecond = LCS(s1, s2, idx1, idx2+1);
            
            return t[idx1][idx2] = max(moveFirst, moveSecond);
        }
    }
    
public:
    int shortestCommonSupersequence(string &s1, string &s2) {
        n = s1.length(), m = s2.length();
        memset(t, -1, sizeof(t));
        
        int lcs = LCS(s1, s2, 0, 0);
        
        return n + m - lcs;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)