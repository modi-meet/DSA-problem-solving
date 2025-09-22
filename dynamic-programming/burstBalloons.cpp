class Solution {
    int t[302][302];

private:
    int solve(int i, int j, vector<int>& nums){
        if(i > j) return 0;

        if(t[i][j] != -1) return t[i][j];

        int ans = INT_MIN;

        for(int k=i; k <= j; k++){
            int tempAns = solve(i, k-1, nums) + solve(k+1, j, nums) + nums[i-1]*nums[k]*nums[j+1];

            ans = max(ans, tempAns);
        }

        return t[i][j] = ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        memset(t, -1, sizeof(t));
        
        int i = 1, j = n;

        return solve(i, j, nums);
    }
};
// Time ComplexitY: O(n^3)
// Space Complexity: O(n^2)

// burst the balloons -> all of them
// maximum coins we need to collect

// Each time select a balloon and pop it. 
// collect coins by multiplying curr with left & right adj elements.