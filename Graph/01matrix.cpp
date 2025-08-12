class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // {{row,col}, distance}
        queue< pair<pair<int, int>, int> > q;
        vector<vector<int>> seen(m, vector<int>(n, 0));
        
        // Step 1: Push all 0's into queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) {
                    q.push({{i, j}, 0});
                    seen[i][j] = 1;
                }
            }
        }

        vector<vector<int>> distance(m, vector<int>(n, 0));
        int row_d[4] = {-1, 1, 0, 0};
        int col_d[4] = {0, 0, -1, 1};


        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int row = curr.first.first;
            int col = curr.first.second;
            int dist = curr.second;
            
            for(int k = 0; k < 4; k++) {
                int nrow = row + row_d[k];
                int ncol = col + col_d[k];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    if(!seen[nrow][ncol]) {
                    seen[nrow][ncol] = 1;
                    distance[nrow][ncol] = dist + 1;
                    q.push({{nrow, ncol}, dist + 1});
                    }
                }
            }
        }
        return distance;
    }
};