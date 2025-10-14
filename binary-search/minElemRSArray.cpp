// Find Minimum in Rotated Sorted Array (no duplicate elements)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        int low = 0, high = n-1;

        while(low <= high){
            int mid = (high+low)/2;

            // ans = min(ans, nums[mid]);

            if(nums[low] <= nums[mid]) { // left half sorted
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            else { // right half sorted
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};
// Time Complexity: O(logn)