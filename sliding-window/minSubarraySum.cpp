// Minimum Size Subarray Sum
// return the minimal length of a subarray whose sum is greater than or equal to target. 
// If there is no such subarray, return 0 instead.

// BRUTE FORCE
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum >= target) {
                    minLength = min(minLength, j - i + 1);
                    break; // slight optimization
                }
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = 0;
        int sum = 0, minLength = INT_MAX;

        while(r < n){
            sum += nums[r]; 

            while(sum >= target){ //try minimize the size of window
                minLength = min(minLength, r-l+1);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

/* Explanation
- two pointers (left and right) to maintain a window over the array.
- Expand right to include elements until the window sum ≥ target, then try shrinking from the left to minimize the window size.
- store minimum window size where sum ≥ target.alignas

And, that's it!
*/