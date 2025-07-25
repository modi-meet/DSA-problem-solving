// Two Sum – Input Array is Sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // --------------------------------------------
        // 1. Brute Force Approach
        /*
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i + 1, j + 1}; // 1-indexed
                }
            }
        } */
        // TC: O(n^2), SC: O(1)

        // --------------------------------------------
        // 2. Binary Search on Answer
        // binary search for (target - nums[i])
        /*
        for (int i = 0; i < n; i++) {
            int num = target - nums[i];
            int l = i + 1, r = n - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (nums[mid] == num) return {i + 1, mid + 1};
                else if (nums[mid] > num) r = mid - 1;
                else l = mid + 1;
            }
        } */
        // TC: O(n * log n), SC: O(1)

        // --------------------------------------------
        // 3. Two Pointer Approach
        int i = 0, j = n - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum == target) return {i + 1, j + 1}; // 1-indexed answer
            else if (sum > target) j--;
            else i++;
        }
        // TC: O(n), SC: O(1)
        return {};
    }
};
