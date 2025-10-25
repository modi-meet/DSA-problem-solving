// Kth Missing Positive Number
// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 1, high = n-1;

        while(low <= high) {
            int mid = (low + high) / 2;

            int missing = arr[mid] - (mid+1);

            if(missing < k){ // eleminate left
                low = mid + 1;
            }
            else high = mid - 1;

        }
    
        return low + k;    
    }
};

// Time Complexity: O(log N)