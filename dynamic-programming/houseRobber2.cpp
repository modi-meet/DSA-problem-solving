// House Robber 2
// All houses at this place are arranged in a circle.
// That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected.
// Return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int robHelper(vector<int>& nums){
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

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> vec1, vec2;

        for(int i=0; i<n; i++){
            if(i != 0) vec1.push_back(nums[i]);
            if(i != n-1) vec2.push_back(nums[i]);
        }

        return max(robHelper(vec1), robHelper(vec2));
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)