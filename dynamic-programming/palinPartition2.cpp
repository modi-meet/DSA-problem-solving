// Palindrome Partitioning 2
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s.

class Solution {
    int t[1002][1002];
    
private:
    bool isPalin(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
            
    int solve(int i, int j, string& s){
        if(i >= j) return 0;
        
        if(isPalin(i, j, s)) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++){
            int left, right;
            if(t[i][k] != -1) left = t[i][k];
            else {
                left = t[i][k] = solve(i, k, s);
            }

            if(t[k+1][j] != -1) right = t[k+1][j];
            else {
                right = t[k+1][j] = solve(k+1, j, s);
            }

            int tempAns = left + right + 1; // +1 fpr partition 
            
            ans = min(ans, tempAns);
        }
        
        return t[i][j] = ans;
    }
public:
    int palPartition(string &s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        
        int i=0, j = n-1;
        
        return solve(i, j, s);
    }
};
// Time ComplexitY: O(n^3)
// Space Complexity: O(n^2)