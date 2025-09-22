// Target Sum
// given an integer array nums and an integer target.

class Solution {
    int n;
    
private:
    int findWays(vector<int>& nums, int target, int idx, int currentSum) {
        if (idx >= n) {
            return currentSum == target ? 1 : 0;
        }
        
        int addPositive = findWays(nums, target, idx + 1, currentSum + nums[idx]);
        int addNegative = findWays(nums, target, idx + 1, currentSum - nums[idx]);
        
        return addPositive + addNegative;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        return findWays(nums, target, 0, 0);
    }
};

// Recursion + memoized
class Solution {
    int n;
    int t[22][1002];

private:
    int countSubsetSum(vector<int>& nums, int target, int idx) {
        if(idx >= n) {
            if(target == 0) return 1;

            return 0;
        }

        if(t[idx][target] != -1) return t[idx][target];

        int take = 0;
        if(nums[idx] <= target) take = countSubsetSum(nums, target - nums[idx], idx+1);
        int notTake = countSubsetSum(nums, target, idx+1);

        return t[idx][target] = take + notTake;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > totalSum) return 0;
        if ((target + totalSum) % 2 != 0) return 0; 

        int sum = (target + totalSum) / 2;

        memset(t, -1, sizeof(t));

        return countSubsetSum(nums, sum, 0); 
    }
};

// Tabulation
class Solution {
    int M = 1e9+7;
    
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        long long totalSum = accumulate(A.begin(), A.end(), 0);
        
        if(abs(target) > totalSum) return 0;
        if ((totalSum + target) % 2 != 0) return 0;
        
        int sum = (target + totalSum) / 2;
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                // not take
                dp[i][j] = dp[i-1][j];
                
                // take if possible
                if(A[i-1] <= j){
                    dp[i][j] = (dp[i][j] + dp[i-1][j - A[i-1]]) % M;
                }
            }
        }
        
        return dp[n][sum];
    }
};
// Time complexity: O(n*sum)
// Space complexity: O(n*sum)

// Count number of ways that sum can become 
