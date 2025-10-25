// Minimize Max Distance to Gas Station
// Given arr represting sas stations at positions arr[0], arr[1], ..., arr[n-1]. Now, add k more gas stations so that, the maximum distance between adjacent gas stations, is minimized. 
// Find the smallest possible value of d. Find the answer exactly to 2 decimal places.

class Solution {
  public:
    double minMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        vector<int> secPlaced(n-1, 0);
        
        while(k-- > 0) {
            long double maxDiff = -1;
            int maxIdx = -1;
            
            for(int i=0; i+1<n; i++) { // looking for minimum section length
                long double diff = arr[i+1] - arr[i];
                long double secLen = diff / (long double)(secPlaced[i] + 1);
                
                if(secLen > maxDiff) {
                    maxDiff = secLen;
                    maxIdx = i;
                }
            }
                        
            secPlaced[maxIdx]++;
        }
        
        long double maxDist = -1;
            
        for(int i=0; i+1<n; i++) {
            long double diff = arr[i+1] - arr[i];
            long double secLen = diff / (long double)(secPlaced[i] + 1);
            
            maxDist = max(maxDist, secLen);
        }
        
        
        return (double)maxDist;
    }
};
// Time Complexity: O(n*k)
// Space Complexity: O(n)

// Better Approach
class Solution {
  public:
    double minMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        vector<int> secPlaced(n-1, 0);
        priority_queue<pair<long double, int>> pq; // max Heap
        
        for(int i=0; i+1 < n; i++) {
            pq.push({arr[i+1] - arr[i], i});
        }
        
        while(k-- > 0) {
            auto [curr, idx] = pq.top();
            pq.pop();
            
            secPlaced[idx]++;
            
            long double diff = arr[idx+1] - arr[idx];
            long double newDiff = diff / (long double) (secPlaced[idx] + 1);
            
            pq.push({newDiff, idx});
        }
        
        return pq.top().first;
    }
};
// Time Complexity: O(n*logn) + O(k*logn)
// Space Complexity: O(n)

// Optimal Approach
class Solution {
  public:
    int gasReq(long double dist, vector<int> &arr) {
        int ans = 0;
        
        for(int i=0; i+1<arr.size(); i++) {
            int reqCnt = (arr[i+1] - arr[i]) / dist;
            
            if((arr[i+1] - arr[i]) == (dist * reqCnt)) {
                reqCnt--; 
            } // overflowed
            
            ans += reqCnt;
        }
        
        return ans;
    }
    
    double minMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        long double high = -1;
        for(int i=0; i+1<n; i++) {
            high = max(high, (long double)arr[i+1] - arr[i]);
        }
        
        long double low = 0;
        while(high - low > 1e-6) {
            long double mid = low + (high - low)/2;
            
            int cnt = gasReq(mid, arr);
            
            if(cnt > k) 
                low = mid;
            else 
                high = mid;
        }
        
        return high;
    }
};
// Time Complexity: O(n*logn)
// Space Complexity: O(1)