// Remove K Digits
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

class Solution {
    public String removeKdigits(String num, int k) {
        int n = num.length();
        if(k == n) return "0";

        Stack<Character> st = new Stack<>(); // increasing order

        for(int i=0; i < n; i++){
            char ch = num.charAt(i);
            while(!st.isEmpty() && k > 0 && st.peek()-'0' > ch-'0'){
                st.pop();
                k--;
            }

            st.push(ch);
        }
        
        // k>0 ; remove last k digits
        while (k > 0 && !st.isEmpty()) { //O(k)
            st.pop();
            k--;
        }

        StringBuilder ans = new StringBuilder();
        while (!st.isEmpty()) {
            ans.append(st.pop());
        }

        ans.reverse();

        int idx = 0; // leading zeroes
        while (idx < ans.length() && ans.charAt(idx) == '0') {
            idx++;
        }

        if (idx == ans.length()) return "0";
        return ans.substring(idx);      
    }   
}
// Time Complexity: O(n)+O(k), Space COmplexity: O(n)

/*
Important Edge Cases: 
- k should be (k < n); if k==n return 0 as all numbers will be removed
- resultant number caannot contain leading zero, remove if any.
- if the given number is already smallest, remove last k digits.
*/
