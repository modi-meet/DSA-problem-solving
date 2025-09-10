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
    public boolean canPartition(int[] nums) {
        int n = nums.length;

        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        
        boolean[][] dp = new boolean[n+1][target+1];
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][target];
    }
};