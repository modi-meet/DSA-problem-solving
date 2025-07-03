// Given a string s, return true if it is a palindrome, or false otherwise.
// s consists only of printable ASCII characters
class Solution {
public:
    bool isAlphaNum(char ch){
        if(ch >= '0' && ch <= '9' || tolower(ch) >= 'a' && tolower(ch) <= 'z'){
                return true;
        }

        return false;
    }
    
    bool isPalindrome(string s) {
        int st=0, end = s.length()-1;

        while(st<end){
            if(!isAlphaNum(s[st])) st++; continue;
            if(!isAlphaNum(s[end])) end--; continue;
            if(tolower(s[st]) != tolower(s[end])) return false;

            st++; end--;           
        }
        return true;
    }
};
// TIME COMPLEXITY : O(N), S.C : O(1)

/*
Two Pointer Technique
- To check palindrome, the string should be printed same from both the ends.
- take a pointer at the start and one at the end of the string
- move both pointers simultanoeuly to check whether both characters are same or not.
- Here's the twist:
    - string can have any ASCII characters : smallcase, upppercase, characters, blank space etc.
- So, if both l and r characters are alpha-num, than compare for similarity
- Otherwise, move the pointer to skip the non alpha-num character.
- Iterate till left is less than right pointer.

And, that's it!
*/