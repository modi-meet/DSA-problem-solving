// Valid Parenthesis
class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (char ch : str) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty() || // stack is empty & closing bracket is encountered; return false
                    (ch == ')' && st.top() != '(') ||
                    (ch == '}' && st.top() != '{') ||
                    (ch == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
// Time Complexity: O(n), Space Complexity: O(n) (Auxillary stack)