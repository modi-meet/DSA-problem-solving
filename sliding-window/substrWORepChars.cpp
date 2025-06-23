// Longest Substring Without Repeating Characters

// Brute Force
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;
            for (int j = i; j < n; j++) {
                if (seen.count(s[j])) break;

                seen.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
// Time Complexity : O(n²) and space complexity : O(n) (set for each element)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> set;

        int r = 0, l = 0;
        int ans = 0;

        while(r<n){           
            if(!set.count(s[r])){
                set.insert(s[r]);   
                ans = max(ans, r - l + 1);
                r++;
            } else {
                set.erase(s[l]);
                l++;
            }        
        }

        return ans;
    }
};
// Time Complexity : O(n) and space complexity : O(n) (set initialized only once)