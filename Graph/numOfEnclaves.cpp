// Number of Enclaves
// Given an m x n binary matrix grid, where 0 represents a `sea` cell and 1 represents a `land` cell.
// A 'move' consists of walking from one land cell to another adjacent (4-directionally) land cell 
// Return the number of non-boundary '1's that are not reachable by any 'move's.
 
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> seen(n, vector<int>(m, 0));

        queue<pair<int,int>> q;

        // Top edge, Bottom edge, Left edge, Right edge
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // first row, first col, last row, last col
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        seen[i][j] = 1;
                    }
                }
            }
        }
        
        int row_d[4] = {-1,1,0,0};
        int col_d[4] = {0,0,-1,1};

        /// BFS
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            seen[row][col] = 1;

            for(int k=0; k<4; k++){
                int nrow = row + row_d[k];
                int ncol = col + col_d[k];

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m){
                    if(!seen[nrow][ncol] && grid[nrow][ncol] == 1){ // isLand and not seen
                        seen[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        int count = 0;

        // unseen 1's
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && seen[i][j] != 1) count++;
            }
        }

        return count;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// boundary 1's are reachable
// from boundary ones, mark all connected as visited
// return no. of unvisited 1's