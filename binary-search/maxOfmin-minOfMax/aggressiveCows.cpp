// Aggressive Cows
// Given an array with unique elements, which denote the positions of stalls. Also given an integer k which denotes the number of aggressive cows. 
// The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Brute force approach
class Solution {
    int n;
  public:
    bool canWePlace(vector<int> &arr, int k, int dist) {
        int count = 1;
        int prev = arr[0];
        
        for(int i=1; i<n; i++){
            if(arr[i] - prev >= dist) {
                count++;
                prev = arr[i];
            }
        }
        
        return count >= k;
    } 
    
    int aggressiveCows(vector<int> &arr, int k) {
        n = arr.size();
        sort(arr.begin(), arr.end());
        
        int low = 1, high = arr[n-1] - arr[0];
        int ans = high;
        
        for(int betweenDist = 1; betweenDist <= high; betweenDist++) {
            if(canWePlace(arr, k, betweenDist)) {
                continue;
            } else return betweenDist - 1; // return previousDistance which was valid
        }
        return ans;
    }
};
// Time Complexity: O(m * n)

// Optimal Approach
class Solution {
    int n;
  public:
    bool canWePlace(vector<int> &arr, int k, int dist) {
        int count = 1;
        int prev = arr[0];
        
        for(int i=1; i<n; i++){
            if(arr[i] - prev >= dist) {
                count++;
                prev = arr[i];
            }
        }
        
        return count >= k;
    } 
    
    int aggressiveCows(vector<int> &arr, int k) {
        n = arr.size();
        sort(arr.begin(), arr.end());
        
        int low = 1, high = arr[n-1] - arr[0];
        int ans = high;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(canWePlace(arr, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
                
        }
        return ans;
    }
};
// Time Complexity: O(logm * n)