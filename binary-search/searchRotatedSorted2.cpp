// Search in Rotated Sorted Array 2 (duplicate elements allowed)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target) return true;

            // Important
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++; high--;
                continue;
            }

            if(nums[low] <= nums[mid]) { // left half sorted
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid-1;
                }
                else low = mid+1;
            }
            else { // right half is sorted
                if(target >= nums[mid] && target <= nums[high])
                    low = mid+1;
                else high = mid - 1;
            }
        }
        return false;
    }
};
// Time Complexity: O(logn) (avg) 
// Time Complexity: O(n/2) (worst case)