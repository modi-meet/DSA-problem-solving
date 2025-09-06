// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

// Recursion + memoized Approach
class Solution {
    int n;
    Boolean[][] dp;

    private boolean solve(int[] arr, int target, int idx){
        if(target == 0) return true;
        if(target < 0 || idx >= n) return false;

        if(dp[target][idx] != null) return dp[target][idx];

        if(target - arr[idx] >= 0) {
            return dp[target][idx] = solve(arr, target-arr[idx], idx+1) || solve(arr, target, idx+1);
        } else {
            return dp[target][idx] = solve(arr, target, idx+1);
        }
    }

    public boolean canPartition(int[] nums) {
        n = nums.length;
        int sum = 0;

        for(int i=0; i<n; i++) sum += nums[i];

        if(sum % 2 == 1) return false; // odd sum not possible
        int target = sum/2;

        dp = new Boolean[target+1][n];

        return solve(nums, target, 0);
    }
}
// Only Recursion : TC - O(2^n) (Exponential)

// Time Complexity: O(n*m)
// Space Complexit: O(n*m)

// Tabulation
class Solution {