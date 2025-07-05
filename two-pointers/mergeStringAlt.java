// Merge Strings Alternately
// Given two strings, merge them aleternately by character. If a string is longer than the other, append the additional letters onto the end of the merged string. 
class Solution {
    public String mergeAlternately(String word1, String word2) {
        int n1 = word1.length(), n2 = word2.length();
        int it1 = 0, it2 = 0;
        StringBuilder ans = new StringBuilder();
        
        while(ans.length() < n1+n2){
            if(it1 < n1 ) ans.append(word1.charAt(it1++));
            if(it2 < n2) ans.append(word2.charAt(it2++));
        }

        return ans.toString();
    }
}
// Time Complexity: O(n1+n2), Space Complexity: O(n1+n2) (resultant string)