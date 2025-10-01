// Scrambled string

class Solution {
    unordered_map<string, bool> mp;
private:
    bool solve(string s1, string s2){
        if(s1 == s2) return true;
        if(s1.length() != s2.length()) return false;

        string key = s1 + "_" + s2;
        if(mp.count(key)) return mp[key];

        int n = s1.length();

        bool ans = false;
        for(int i=1; i<n; i++){
            /*
            "great"  "eatgr"

            if swapped at i = 2

            s1.substr(0, i) "gr"  with s2.substr(n-i, i)  "gr"
            
            && 
            
            s1.substr(i, n-i) "eat"  with s2.substr(0, n-i)  "eat"
            */

            /*
            "great"  "great"

            if not swapped at i = 2

            s1.substr(0, i) "gr"  with s2.substr(0, i)  "gr"
            
            && 
            
            s1.substr(i, n-i) "eat"  with s2.substr(i, n-i)  "eat"
            */

            bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i)) &&
                                solve(s1.substr(i, n-i), s2.substr(i, n-i));
            bool swapped = solve(s1.substr(0, i), s2.substr(n-i, i)) &&
                            solve(s1.substr(i, n-i), s2.substr(0, n-i));

            if(swapped || not_swapped) {
                ans = true;
                break;
            }

        }
        return mp[key] = ans;
    }
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        
        return solve(s1, s2);
    }
};

// After dividing, 
// - we have two options: 
//  1. swap
//  2. don't swap