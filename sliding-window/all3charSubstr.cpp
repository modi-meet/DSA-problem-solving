// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for(int i=0; i<n-1; i++){
            vector<int> freq(3, 0);
            freq[s[i]-'a']++;

            for(int j=i+1; j<n; j++){
                freq[s[j]-'a']++;

                if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                    count += n-j; 
                    break;
                }
            }
        }
        return count;
    }
};
// TIME COMPLEXITY - O(N^2), Space Complexity - O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        vector<int> freq(3, 0);
        int l = 0, r = 0;
        int ans = 0;
        
        while(r < n){
            char ch = s[r];
            freq[ch-'a']++;

            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                ans += n-r;

                freq[s[l]-'a']--;
                l++;
            }
            r++;
        }

        return ans;
    }
};
// TIME COMPLEXITY - O(N), Space Complexity - O(1)

/*
- minimum requirement - all 3 characters should be there in the substring(/window)
- anything extra is fine
- as soon as all 3 characters are present in the window, add all remaining character window count to ans
    - because every character will give each new substring.
- After counting, shrink the window till we get new substring (not all 3 cahracters are present)
- Repeat the same for new window

And, that's it!
*/