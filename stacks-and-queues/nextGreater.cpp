// Next Greater Element
// Brute Force Approach
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> NGE(n, -1);

        unordered_map<int, int> mp; // store NGE of nums2 elements
        // next greater elements for nums2
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums2[j] > nums2[i]) { // next greater found
                    NGE[i] = nums2[j];
                    break;
                }
            }
            mp[nums2[i]] = NGE[i];
        }

        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};
// Time Complexity : O(n1 + n2^2), n2 = size of nums2
// Space Complexity : O(n1+n2), for map and NGE vector

// Optimized Approach (Monotonic Stack)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        stack<int> st; // stores elements of nums2 in decreasing order
        unordered_map<int, int> map;

        for(int i = n2-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]) st.pop(); 

            if(st.empty()){  
                map[nums2[i]] = -1;
            } else{
                map[nums2[i]] = st.top(); 
            }

            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int val : nums1){
            ans.push_back(map[val]);
        }       
        return ans;
    }
};
// Time Complexity : O(n1+n2)
// Space Complexity : O(n1+n2)