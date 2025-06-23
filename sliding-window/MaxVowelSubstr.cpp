

// Brute force 
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int ans = 0;

        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=i; j<i+k && j<n; j++) {
                if(isVowel(s[j])) cnt++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};
// Time Complexity - O(n*k), Space Complexity - O(1)

// OPTIMAL APPROACH
class Solution {
public:
    bool isVowel(char ch) { // O(1)
        return ch == 'a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int ans = 0;
        int l=0, r=0;
        int vowelCnt = 0;

        while(r<n){ // O(n)
            if(isVowel(s[r])) vowelCnt++;
                                    
            if(r-l+1 > k){         //slide the window
                if(isVowel(s[l])) vowelCnt--;
                l++;
            } 
            
            r++;
            ans = max(ans, vowelCnt);
        }

        return ans;
    }
};
// Time Complexity : O(N), Space Complexity : O(1)