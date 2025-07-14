// given an absolute path for a Unix-style file system, which always begins with a slash '/'. Task is to transform this absolute path into its simplified canonical path.

class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path);
        stack<string> st;

        while(getline(ss, token, '/')){
            if(token == "" || token == ".") continue; // no need to add in stack

            if(token == "..") {
                if(!st.empty()) st.pop();
            }
            else st.push(token);
        }

        if(st.empty()) return "/";
      
        string ans = "";

        while(!st.empty()){
            ans = "/" + st.top() + ans; // add prev path at the end of the new path
            st.pop();
        }
        
        return ans;
    }
};
// Time Complexity: O(n), Space Complexity: O(n)+O(n) (stack + answer string)

// NOTE: String stream is used to split the string by '/' delimiter.