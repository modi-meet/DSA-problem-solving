//  Find First and Last Position of Element in Sorted Array

//BRUTE Force : TC - O(N), SC - O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccIdx = -1, lastOccIdx = -1;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(target == nums[i]) {
                if(firstOccIdx == -1) firstOccIdx = i;

                lastOccIdx = i;
            }
        }

        return {firstOccIdx, lastOccIdx};
    }
};


//OPTIMAL Approach : TC - O(2*logN), SC - O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n-1;
        int firstOccIdx = -1, lastOccIdx = -1;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[mid] == target) {
                firstOccIdx = mid;
                end = mid-1; //shrink the right, to get first occurence  
            }
            else if(nums[mid] < target) st = mid+1;
            else end = mid - 1;
        }

        st = 0, end = n-1;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[mid] == target) {
                lastOccIdx = mid;
                st = mid+1; //shrink the left, to get last occurence  
            }
            else if(nums[mid] < target) st = mid+1;
            else end = mid - 1;
        }

        return {firstOccIdx, lastOccIdx};
    }
};

// Using in-built functions : TC - O(2*logN), SC - O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int n = nums.size();

        int lb = lower_bound(nums.begin(), nums.end(), tar) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), tar) - nums.begin();

        if(lb == n || nums[lb] != tar) return {-1, -1};

        return {lb, ub-1};
    }
};