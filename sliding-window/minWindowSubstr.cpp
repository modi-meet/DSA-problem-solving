// *Minimum Window Substring*
class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int n = s.length();

        unordered_map<char, int> freq; // 1. store char freq of t
        for(char ch : t){
            freq[ch]++;  
        }

        int l = 0, r = 0, minLen = INT_MAX;
        int startIdx = -1; //start index of minLen substring
        int cnt = 0; // no. of element present in both `t` and `curr window`
        int required = t.size(); //no. of char in str `t`

        while(r < n){
            char ch = s[r];
            if (freq[ch] > 0) { // present in `t`
                cnt++;  //include the character
            }
            freq[ch]--;   //reduce as it has been in the window; not required in-future

            while(cnt == required){  //exact same freq
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    startIdx = l; //start index of minimum len window
                }

                freq[s[l]]++;
                if(freq[s[l]] > 0) cnt--;
                //=> by shrinking the window, character present in both t and currWindow was removed

                l++;
            }

            r++;
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};
// Time Complexity : O(n)
// Space Complexity : O(t)

/* EXPLANATION
Given two strings s and t, 
return the minimum window substring of s such that - every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".

The smallest substring that has all characters of t in it (any order order) is the answer.

*Instead keeping the temporary string, keep the track of its starting index and the length(minimum)

1. store freq of characters in t
2. **expand window till - all required characters in freq are not found in the window
3. Iteration
    - if the current character is presetn in t, 
    - check if it is required to include in the window with freq map
    - *If yes, update the count - cnt (no. of chars that are present in both `t` and curr window)
4. Shrinking
    - If the t.length() characters are found in the window(cnt == t.length())
        - Count length of the window
            - If less than (minLen) ? Update (minLen) and starting Idx of minWindow
        - go for minimum window size
    - Shrink.
    - If the shrinked char was present in t, update its freq and the cnt
5. Return the resultant substring from startingIdx to minLen if possible, else "".

And, that's it!
*/