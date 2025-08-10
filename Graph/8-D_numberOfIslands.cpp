// Find the number of islands
// Given a grid of size n*m consisting of 'W's (Water) and 'L's (Land). Find the number of islands.
// Condition: An island is formed by connecting adjacent lands in all 8 directions.

// DFS Approach
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &seen){
        int n = grid.size();
        int m = grid[0].size();
        seen[row][col] = 1;
        
        for(int i=-1; i<=1; i++){ // for all 8 directions
            for(int j=-1; j<=1; j++){
                int nrow = row+i;
                int ncol = col+j;
                
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m){
                    if(grid[nrow][ncol] == 'L' && seen[nrow][ncol] == 0){
                        seen[nrow][ncol] = 1;
                        dfs(nrow, ncol, grid, seen);
                    }
                }
            }
        }
    }
    
public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        
        vector<vector<int>> seen(n, vector<int>(m, 0));
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == 'L' && seen[row][col] == 0){ //is land & unseen
                    islands++;
                    dfs(row, col, grid, seen);
                }
            }
        }
        
        return islands;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// BFS Approach
class Solution {
private:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &seen){
        int n = grid.size();
        int m = grid[0].size();
        seen[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(int i=-1; i<=1; i++){ // for all 8 directions
                for(int j=-1; j<=1; j++){
                    int nrow = curr.first+i;
                    int ncol = curr.second+j;

                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m){
                        if(grid[nrow][ncol] == 'L' && !seen[nrow][ncol]){
                            seen[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
    }

public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        
        vector<vector<int>> seen(n, vector<int>(m, 0));
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == 'L' && seen[row][col] == 0){ //is land & unseen
                    islands++;
                    bfs(row, col, grid, seen);
                }
            }
        }
        return islands;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)