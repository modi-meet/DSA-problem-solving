// Replace 'O's with 'X's
// Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' in 4-D.

class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& cannotBeReplaced){
        int n = mat.size();
        int m = mat[0].size();
        
        cannotBeReplaced[row][col] = 1;
        
        int row_d[4] = {-1,1,0,0};
        int col_d[4] = {0,0,-1,1};
        
        for(int k=0; k<4; k++){
            int nrow = row + row_d[k];
            int ncol = col + col_d[k];
            
            if(nrow >= 0 && nrow < n && ncol < m && ncol >= 0){
                if(mat[nrow][ncol] == 'O' && !cannotBeReplaced[nrow][ncol]){
                    cannotBeReplaced[nrow][ncol] = 1;
                    dfs(nrow, ncol, mat, cannotBeReplaced);
                }
            }
        }
    }
    
public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Initially marking all can be replaced
        vector<vector<int>> cannotBeReplaced(n, vector<int> (m, 0));
        
        
        // Top edge
        for(int j=0; j<m; j++){
            if(mat[0][j] == 'O') {
                dfs(0, j, mat, cannotBeReplaced);
            }
        }
        
        // Bottom edge
        for(int j=0; j<m; j++){
            if(mat[n-1][j] == 'O') {
                dfs(n-1, j, mat, cannotBeReplaced);
            }
        }
        
        // Left edge
        for(int i=0; i<n; i++){
            if(mat[i][0] == 'O'){
                dfs(i, 0, mat, cannotBeReplaced);
            }
        }
        
        // Right edge
        for(int i=0; i<n; i++){
            if(mat[i][m-1] == 'O'){
                dfs(i, m-1, mat, cannotBeReplaced);
            }
        }
        
        vector<vector<char>> grid = mat;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'O' && cannotBeReplaced[i][j] == 0){ // is an 'O' & can be replaced
                    grid[i][j] = 'X'; // replace
                }
            }
        }
        
        return grid;
    }
};

// Go to boundary O's
// mark all connected O's as cannot be replaced
// replace all other O's with X's.