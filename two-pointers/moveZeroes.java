// Move Zeroes to the end
//Optimized approach-1 : Two-pointers
class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int zeroIdx = 0;

        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                if(i != zeroIdx){ // swap(zeroIdx, i)th elements
                    int temp = nums[i];
                    nums[i] = nums[zeroIdx];
                    nums[zeroIdx] = temp; 
                }
                zeroIdx++;
            }
        }
    }
}
// Time Complexity: O(n), Space Complexity: O(1)
// Explanation: if zero element is found, swap it with the next non-zero element. (only move zero-th element index forward if it is swapped)

// Optimized approach-2 : Snowball technique / window
class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int snowball_size = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                snowball_size++;
            } else {
                if(snowball_size > 0){
                    int temp = nums[i];
                    nums[i] = 0;
                    nums[i-snowball_size] = temp;
                }
            }
        }
    }
}
// Time Complexity: O(n), Space Complexity: O(1)
// Explanation: if zero element is found, increase the snowball size. 
//              if non-zero element is found:
// Imagine snowball as the chunck of zero elemets found so far, and replace non-zero element with the first zero in the chunk.

// And, that's it!