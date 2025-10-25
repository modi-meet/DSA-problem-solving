// Maximum Number of Distinct Elements After Operations
// You are allowed to perform the following operation on each element of the array at most once:
// Add an integer in the range [-k, k] to the element.
// Return the maximum possible number of distinct elements in nums after performing the operations.

class Solution {
    int n;
public: 
    bool ispossible(vector<int>& nums, int k, int mid) {
        // range = {-k, k}
        int count = 0;
        long long current = LLONG_MIN;

        for(int i=0; i<n; i++) {
            int left = nums[i] - k;
            int right = nums[i] + k;

            if(current < left) current = left;

            if(current <= right) {
                count++;
                current++;
            }

            if(count >= mid) return true;
        }

        return false;
    }

    int maxDistinctElements(vector<int>& nums, int k) {
        n = nums.size();
        if(n == 0) return 0;

        sort(nums.begin(), nums.end());

        int low = 0, high = n;
        int ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(ispossible(nums, k, mid)) {
                ans = mid;
                low = mid + 1;
            } 
            else high = mid - 1;
        }

        return ans;
    }
};
// Time Complexity: O(N*logN)

// Observations
// - the answer will always be between, 1 - n
// - apply binary search on answer and find for the bigger answer
// how to calculate the no. of distinct element in an array very effficiently