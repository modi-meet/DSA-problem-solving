// Floyd Warshall Algorithm
// It is a multi-sourced shortest distance algorithm
// Use case: when shortest distance b/w every node to every other node is required.

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        // vector<vector<int>> dist(n, vector<int> (n, 1e8));
        // for(int r=0; r<n; r++) {
        //     for(int c=0; c<n; c++) {
        //         if(r == c) dist[r][c] = 0;
        //     }
        // }
        
        for(int via=0; via<n; via++) {
            for(int r=0; r<n; r++) {
                for(int c=0; c<n; c++) {
                    if(dist[r][via] == 1e8 || dist[via][c] == 1e8){
                        continue;
                    }
                    
                    dist[r][c] = min(dist[r][c], dist[r][via] + dist[via][c]);
                }
            }
        }
        
        // Detect -ve cycle 
        for(int r=0; r<n; r++) {
            if(dist[i][i] < 0) return -1; 
        }
    
    }
};
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)