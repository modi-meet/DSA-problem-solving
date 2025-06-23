// Longest Repeating Character Replacement
// given a string s and an integer k, choose any character of the string and change it to any other character
// can perform this operation at most k times.

class Solution {
public: // BRUTE Force
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans=0;
        int unique = 0;

        for(int l=0; l<n-1; l++){
            vector<int> freq(26, 0);
            int maxChar = 0; // maximum frequency character in window
            
            for(int r=l; r<n; r++){
                int ch = s[r]-'A';
                freq[ch]++;

                maxChar = max(maxChar, freq[ch]);

                unique = (r-l+1) - maxChar;
                if(unique <= k) ans = max(ans, r-l+1);
                else break;
            }
        }
        return ans;
    }
};
// TIME COMPLEXITY - O(N^2), Space Complexity - O(1)

//OPTIMAL Approach
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        //Sliding Window
        vector<int> freq(26, 0);
        int l=0, r=0;
        int maxLen = 0, maxFreqElem = 0;

        while(r<n){
            int ch = s[r]-'A';
            freq[ch]++;
            maxFreqElem = max(maxFreqElem, freq[ch]);

            if((r-l+1) - maxFreqElem > k){  //no. of unique chars in window > k; only k uniques are allowed
                freq[s[l]-'A']--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};
// TIME COMPLEXITY - O(N), Space Complexity - O(1)

/* EXPLANATION

Task is to return the Longest substring whose all characters are equal after K operation
- So, only k characters are allowed to be changed
Which character to change?
- least appearing character in the substring!
- the most appearing char in the substring will help in performin least operations to make all chars equal

-> Compute most appearing char in the substring
-> find no. of unique chars in it (allowed to change them)
-> if unique characters are greater than allowed (k)
    - shrink the window till uniques are less than k
-> calculate longest substring by right-left+1 pointer locations

And, that's it!
*/