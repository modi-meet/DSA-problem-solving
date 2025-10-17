// Find the Smallest Divisor Given a Threshold
// Given an array of integers nums and an integer threshold, choose a positive integer divisor, divide all the array by it, and sum the division's result. 
// Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
// Each result of the division is rounded to the nearest integer greater than or equal to that element.

class Solution {
public:
    int calc_sum(vector<int>& nums, int divisor, int threshold){
        int sum = 0;

        for(auto &num : nums) {
            sum += ceil(1.0 * num / divisor);

            if(sum > threshold) return threshold + 1;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            int mid = low + (high-low)/2;

            int sum = calc_sum(nums, mid, threshold);
            
            if(sum > threshold) {
                low = mid + 1; // increase the divisor, lesser the remainders
            }
            else high = mid-1; 
        }
        return low;
    }
};
// Time Complexity: O(n * log(threshold) )

// after dividing the sum of the new array should be <= threshold