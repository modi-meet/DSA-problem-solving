// The Painter's Partition Problem
// Given an array where each element denotes the length of a board, and an integer k representing the number of painters available. 
// Each painter takes 1 unit of time to paint 1 unit length of a board.
// Determine the minimum amount of time required to paint all the boards, each painter can paint only a contiguous sequence of boards 

class Solution{
    int n;
  public:
    bool canWeTake(vector<int> &arr, int k, int limit) {
        int count = 1;
        int cumSum = arr[0];
        
        for(int i=1; i<n; i++){
            if(cumSum + arr[i] > limit) {
                count++;
                cumSum = arr[i]; // reset, new array allocation started 

                if(count > k) return false; // size exceeded
            }
            else cumSum += arr[i];
        }
        
        return true;
    } 
    
    int splitArray(vector<int> &arr, int k) {
        n = arr.size();
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(canWeTake(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
                
        }
        return ans;
    }
};
// minimize the maximum sum