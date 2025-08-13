// Number of Distinct Islands
//  Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& seen, vector<vector<int>>& grid,
    vector<pair<int, int>>& vec, int row0, int col0) {
        int n = grid.size();
        int m = grid[0].size();
        
        seen[row][col] = 1;
        vec.push_back({row-row0, col-col0}); // (position - base position)
        
        int row_d[4] = {-1,1,0,0};
        int col_d[4] = {0,0,-1,1};
        
        for(int k=0; k<4; k++){
            int nrow = row + row_d[k];
            int ncol = col + col_d[k];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                if(!seen[nrow][ncol] && grid[nrow][ncol] == 1){
                    dfs(nrow, ncol, seen, grid, vec, row0, col0);
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> seen(n, vector<int> (m, 0));
        
        set<vector<pair<int, int>>> set; // Important
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!seen[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> vec; // Important
                    
                    dfs(i, j, seen, grid, vec, i, j); // (can be BFS also) 
                    
                    set.insert(vec);
                }
            }
        }
        return set.size();
    }
};
// Time Complexity: O(n * m * log(n * m))
// Space Complexity: O(n * m)