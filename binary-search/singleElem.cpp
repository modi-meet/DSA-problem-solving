// Single Element in a Sorted Array
// Given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st=0, end = nums.size()-1;

        if(nums.size()==1) return nums[0];

        while(st<=end){
            int mid= st +(end-st)/2;

            if(mid == 0 && nums[0] != nums[1]) return nums[mid];
            if(mid == end && nums[end] != nums[end-1]) return nums[mid];
            
            if(nums[mid-1] != nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];

            if(mid%2 == 0){ // even idx
                if(nums[mid-1]==nums[mid]){ // left half
                    end = mid-1;
                } else{ // right half
                    st = mid+1;
                }
            }
            else{ //odd idx
                if(nums[mid-1]==nums[mid]){ // left half
                    st=mid+1;
                } else { // right half
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};  
// Time Complexity: O(logn)