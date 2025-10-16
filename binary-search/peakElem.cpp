// Find Peak Element
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// nums[-1] = nums[n] = -∞

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int st = 0, end = n-1;
        while(st <= end) {
            int mid = st + (end-st)/2;
            bool left = (mid==0 || nums[mid-1] < nums[mid]); // left chhota
            bool right = (mid == n-1 || nums[mid] > nums[mid+1]); // right chhota

            if(left && right) return mid;
            else if(mid < n-1 && nums[mid] < nums[mid+1]) st = mid+1;
            else end = mid-1;
        }

        return -1;
    }
};
// Time Complexity: O(logn)