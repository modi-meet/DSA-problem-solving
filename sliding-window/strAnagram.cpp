// Find All Anagrams in a String
// Given two strings s and p, return an array of all the start indices of p's anagrams in s.    
class Solution {
public:
    bool allFreqZero(vector<int> &freq){
        for(int i : freq){
            if(i != 0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        if(m>n) return {};

        vector<int> freq(26, 0);
        //freq of char in p
        for(char ch : p){
            freq[ch - 'a']++;
        }

        int i=0, j=0;
        vector<int> ans;

        while(j<n){ // window
            freq[s[j] - 'a']--;

            if((j-i+1) == p.length()){
                if(allFreqZero(freq)) ans.push_back(i);

                freq[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
// TIME COMPLEXITY : O(N), Space Complexity : O(26) 

/*EXPLANATION

Task is to find the anaggram of p in s
 - take the window of size of p
 - move the left pointer further as we get the anagram for p
 - check anagram by stroing frequency of p characters in s
 
And, that's it!
*/