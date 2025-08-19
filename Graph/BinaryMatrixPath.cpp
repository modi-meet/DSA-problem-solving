// Shortest Path in Binary Matrix
// Given an n x n binary matrix grid, return the length of the shortest clear path (only '0' cells can be traveled 8-D) in the matrix. 
// If there is no clear path, return -1.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0) return -1;

        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        queue<tuple<int, int, int>> q; // {dist, i, j}
        
        q.push({1, 0, 0});
        dist[0][0] = 1;

        while(!q.empty()) {
            auto [currDist, i, j] = q.front();
            q.pop();

            for(int r=-1; r<=1; r++) {
                for(int c=-1; c<=1; c++) {
                    int nrow = i+r;
                    int ncol = j+c;

                    if(nrow<n && nrow>=0 && ncol<n && ncol>=0) {
                        if(grid[nrow][ncol] == 0) {
                            if(currDist+1 < dist[nrow][ncol]) {
                                q.push({currDist+1, nrow, ncol});
                                dist[nrow][ncol] = currDist+1;
                            }
                        }
                    }
                }
            }
        }

        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
    }
};
// TC : O(n*n)
// SC : O(n*n)

// Here, Why queue over Priority queue for Dijkstra's algo???
// - The distance from eachcell to another cell will be 1 always, so no quick minimum distance check is required. Hence, no pq.