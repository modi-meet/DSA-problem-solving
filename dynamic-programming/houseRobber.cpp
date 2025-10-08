// House Robber
// Each house has a certain amount of money stashed, 
// the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    // memoization, TC : O(n) || SC : O(n) + O(n)
    // ----------------------------------------//
    int f(vector<int> &nums, int i, vector<int> &dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + f(nums, i+2, dp);  //robCurrHouse
        int notPick = 0 + f(nums, i+1, dp);   //skipCurrHouse

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {   
        vector<int> dp(nums.size(), -1);  //memoization
        return f(nums, 0, dp);
    }
    // ----------------------------------------//

    //Tabulation, TC : O(n) || SC : O(n)
    // ----------------------------------------//
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2 ; i<n; i++){
            int pick = nums[i] + dp[i-2];
            int notPick = 0 + dp[i-1];

            dp[i] = max(pick, notPick);
        }

        return dp[n-1];
    } 
    // ----------------------------------------//
        
    //Space Optimization, TC : O(n) || SC : O(1)
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        int prev1 = max(nums[0], nums[1]);
        int prev2 = nums[0];

        for(int i=2; i<n; i++){
            int pick = nums[i] + prev2;
            int notPick = 0 + prev1;

            prev2 = prev1;
            prev1 = max(pick, notPick);
        }
        return prev1;
    }
};