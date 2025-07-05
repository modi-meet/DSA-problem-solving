// Squares of a Sorted Array : Given asorted integer array nums.
// Return an array of the squares of each number sorted in non-decreasing order.

// Brute Force 
class Solution{
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int arr[] = new int[n];

        for(int i=0; i<n; i++){
            arr[i] = nums[i]*nums[i];
        }
        Arrays.sort(arr);
        return arr;
    }
}
// Time Complexity: O(N*logN), Space Complexity: O(1) (resultant array is not counted)

// Optimal Approach
class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int arr[] = new int[n];

        int l=0, r=n-1;
        int idx = n-1;
        while(l <= r){
            if(Math.abs(nums[r]) > Math.abs(nums[l])){
                arr[idx--] = nums[r]*nums[r];
                r--;
            } else{
                arr[idx--] = nums[l]*nums[l];
                l++;
            }
        }
        return arr;
    }
}
// Time Complexity: O(N), O(1) (resultant array is not counted)

// Use two-pointer on given sorted array:
// 1. take two pointers, one at the start and one at the end of the array.
// 2. Compare the absolute values of pointers
//      - whichever is greater, square it and store in in the resultant array at the *end*.
//      - move the pointer of that value.
// And, that's it!