// Search in Rotated Sorted Array (no duplicate elements)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0, end=nums.size()-1;

        while(st<=end){
            int mid=st+(end-st)/2;

            if(nums[mid]==target) return mid;

            if(nums[st]<=nums[mid]){
                //left side is sorted
                if(nums[st]<=target && target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else{
                //right side is sorted
                if(nums[mid]<target && target<= nums[end]){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }

        }
            return -1;
    }
};
// Time Complexity: O(logn)