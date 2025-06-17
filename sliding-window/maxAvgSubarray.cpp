// Find a contiguous subarray whose length is k that has the maximum average value
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int ans = 0;
        //sum of first k elements
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double maxSum = sum;
        // Sliding window : add one remove one
        for (int i = k; i < n; i++) {
            sum += nums[i];   // Add new element,
            sum -= nums[i - k]; // remove old element
            maxSum = max(maxSum, sum);
        }
        return maxSum / k;
    }
};
// TIME COMPLEXITY : O(N), Space Complexity: O(1)