//  Given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
// For each queries[i]:
// - Select a subset of indices within the range [li, ri] in nums.
// - Decrement the values at the selected indices by 1.
// Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

// Approach - 1
class Solution {
public:
    // BRUTE FORCE
    bool isZeroArrayBrute(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> temp = nums;

        for (auto& qry : queries) {
            int l = qry[0];
            int r = qry[1];
            for (int i = l; i <= r; ++i) {
                if (temp[i] > 0) temp[i]--;
            }
        }

        for (int val : temp) {
            if (val != 0) return false;
        }

        return true;
    }    
};
// Time Complexity: O(Q * N)
// Space Complexity: O(N)

// OPTIMIZED : Difference Array
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  // difference array

        for (auto& qry : queries) {
            int l = qry[0];
            int r = qry[1];

            diff[l] += 1;
            if (r + 1 < n) diff[r + 1] -= 1;
        }

        vector<int> cumSum(n, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += diff[i];
            cumSum[i] = sum;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > cumSum[i]) return false;
        }

        return true;
    }
    // Time Complexity: O(N + Q)
    // Space Complexity: O(N)
};