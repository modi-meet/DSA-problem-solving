// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen=0;

        //BRUTE FORCE
        for(int i=0; i<n; i++){
            int zero = k;
            int count = 0; // one count

            int j=i;
            while(j < n){
                if(nums[j] == 1){
                    count++;
                } 
                else if(zero > 0){  // convert zero to 1
                    count++; //expand the window
                    zero--;  //decrease
                }
                else break;

                j++;
            }

            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};
// TIME COMPLEXITY - O(N^2), Space Complexity - O(1)

//Optimal : (sliding window)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen=0;
        int l=0, r=0;
        int zeroCnt = k;

        while(r < n){
            if(nums[r] == 0){
                zeroCnt--;
            }

            while(zeroCnt < 0){   //shrink the window
                if(nums[l] == 0) zeroCnt++;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;        
    }
};
// TIME COMPLEXITY - O(N), Space Complexity - O(1)

/* EXPLANATION

- return maximum number of consecutive ones
- allowed -> k 0s can be flipped and made 1s
Take a window that slides over all the elements in nums array,
    - maintain a variable that counts number of 0s in the window
    - If the zero Count is more than what is allowed( >k),
        -shrink the window (until zero count is less than k)
    - calculate and update maximum ones (size of the window) each time.

And, that's it!
*/