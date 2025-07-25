// Shifting Letters
// Given a string s of lowercase English letters and an integer array shifts of the same length. 
// for each shifts[i] = x, 
// - shift the first i + 1 letters of s, x times.
// Return the final string after all such shifts to s are applied.

// Brute-force approach
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string ans = s;
        int n = shifts.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                ans[j] = (ans[j] - 'a' + shifts[i]) % 26 + 'a';
            }
        }

        return ans;
    }
};
// Time Complexity: O(N^2)
// Space Complexity: O(N) (resultant string)

// Optimized approach
class OptimizedSolution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        long long toAdd = 0;
        string ans = s;

        for (int shift : shifts)
            toAdd += shift;

        for (int i = 0; i < n; i++) {
            ans[i] = (ans[i] - 'a' + toAdd) % 26 + 'a';
            toAdd -= shifts[i];
        }

        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N) (resultant string)