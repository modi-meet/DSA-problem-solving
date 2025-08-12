// WA Function to find distance of nearest 1 in the grid for each cell.

class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // {{row,col}, distance}
        queue< pair<pair<int, int>, int> > q;
        vector<vector<int>> seen(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    seen[i][j] = 1;
                }
            }
        }
        
        vector<vector<int>> distance(n, vector<int>(m, 0));
        int row_d[4] = {-1,1,0,0};
        int col_d[4] = {0,0,-1,1};
        
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first.first;
            int col = curr.first.second;
            int dist = curr.second;
            
            
            for(int k=0; k<4; k++){
                int nrow = row + row_d[k];
                int ncol = col + col_d[k];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(!seen[nrow][ncol]){
                        seen[nrow][ncol] = 1;
                        dist    ance[nrow][ncol] = dist+1;
                        q.push({{nrow, ncol}, dist+1});
                    }
                }
            }
        }
        return distance;
        
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)