// Minimum Multiplications to reach End
// Given start, end and an array arr of n numbers. 
// At each step, start is multiplied with any number in the array and then mod operation with 10^5 is done to get the new start.

// Find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

class Solution {
    int M = 1e5;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // How to figure out the no. of nodes?
        
        if(start == end) return 0;
        
        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> q;
        // steps, node
        q.push({0, start});
        dist[start] = 0;
        
        while(!q.empty()){
            auto [steps, node] = q.front();
            q.pop();
            
            for(auto num : arr) {
                long long currProd = (num*node)%M;
                
                if(steps+1 < dist[currProd]) {
                    if(currProd == end) return steps+1;
                    
                    q.push({steps+1, currProd});
                    dist[currProd] = steps+1;
                }
            }
        }
        return -1;
    }
};
// TC : O(10^5 * arr.size)
// SC : O(10^5)