// Rotting Oranges
// given an m x n grid where each cell can have one of three values:
// 0 - representing an empty cell,
// 1 - representing a fresh orange, or
// 2 - representing a rotten orange.
// Every minute, any fresh orange that is 4-D adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that no cell has a fresh orange. If this is impossible, return -1.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;

        vector<vector<int>> rot (n, vector<int>(m, 0));

        // {{row, col}, t}
        queue<pair <pair<int,int>, int>> q;

        int freshCnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){ // store already given rotten oranges in queue (at time 0)
                    q.push({{i, j}, 0});
                    rot[i][j] = 2;
                }
                else if(grid[i][j] == 1) freshCnt++;
            }
        }   

        int row_dir[4] = {-1,1,0,0};
        int col_dir[4] = {0,0,-1,1};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int nrow = curr.first.first + row_dir[k];
                int ncol = curr.first.second + col_dir[k];
                int t = curr.second;

                time = max(time, t);

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(grid[nrow][ncol] == 1 && rot[nrow][ncol] != 2){
                        q.push({{nrow, ncol}, t+1});
                        rot[nrow][ncol] = 2;

                        freshCnt--;
                    }
                }
            }
        }

        // check if any fresh oranges left out
        if(freshCnt != 0) return -1;

        return time;
    }
};
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)