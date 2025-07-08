// Next Greater Element in Circular Array
// Brute Force Approach
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<i+n; j++){ // till (i-1)th character in circular manner
                if(nums[j%n] > nums[i]) {
                    nge[i]= nums[j%n];
                    break;
                }
            }
        }
        return nge;
    }
};
// Time Complexity: O(n^2), Space Complexity: O(n)

// Optimized Approach
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> st;
        vector<int> nge(n, -1);

        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]) {
                st.pop();
            }
            if(i < n) { // fill when the iteration in within original elements
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};
// Time Complexity: O(2*n + 2*n), Space Complexity: O(2*n) + O(n)
