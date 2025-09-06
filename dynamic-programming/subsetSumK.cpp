// Perfect Sum Problem
// Given an array arr of non-negative integers and an integer target, 
// the task is to count all subsets of the array whose sum is equal to the given target.

class Solution {
    int n;
    int t[1005][1005];

    int solve(vector<int>& nums, int idx, int target) {
        if(idx == n) {
            if(target == 0) return 1;
            
            return 0;
        }

        if(t[idx][target] != -1) return t[idx][target];

        int take = 0;
        if(nums[idx] <= target) {
            take = solve(nums, idx + 1, target - nums[idx]);
        }

        int notTake = solve(nums, idx + 1, target);

        return t[idx][target] = take + notTake;
    }

public:
    int perfectSum(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        
        return solve(nums, 0, target);
    }
};

class Solution {
    int n;
    int t[1005][1005];

    int solve(vector<int>& nums, int idx, int target) {
        if(idx == n) {
            if(target == 0) return 1;
            
            return 0;
        }

        if(t[idx][target] != -1) return t[idx][target];

        int take = 0;
        if(nums[idx] <= target) {
            take = solve(nums, idx + 1, target - nums[idx]);
        }

        int notTake = solve(nums, idx + 1, target);

        return t[idx][target] = take + notTake;
    }

public:
    int perfectSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        return solve(nums, 0, target);
    }
};