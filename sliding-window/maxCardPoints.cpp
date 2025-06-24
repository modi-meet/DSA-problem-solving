// Maximum Points that Can be Obtain from Cards
// In one step, take one card from the beginning or from the end of the row. Take exactly k cards Score is the sum of the points of the cards taken.
// Given the integer array cardPoints and the integer k, return the maximum score that can be obtain.
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = 0;
        int lsum = 0, rsum = 0;

        for(int i=0; i<k; i++){
            lsum += nums[i];
        }

        maxSum = lsum;
        int rIdx = n-1;
        for(int i = k-1; i >= 0; i--){
            lsum -= nums[i];
            rsum += nums[rIdx];
            rIdx--; 

            maxSum = max(maxSum, lsum+rsum);
        }
        return maxSum;
    }
};
// TIME COMPLEXITY - O(K), Space Complexity - O(1) 

/* EXPLANATION
- first take the sum of the first k elements from the left (lsum), store it as an initial answer.
- swap elements from the left with ones from the right, one by one.
- update the score and maximum each time.
*/