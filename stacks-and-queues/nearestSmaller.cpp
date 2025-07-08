// Nearest Smaller Element to the Left
class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            ans[i] = st.empty() ? -1 : st.top();
                
            st.push(arr[i]);
        }
        
        return ans;
    }
};
// Time Complxity: O(2*n), Space Complexity: O(n)