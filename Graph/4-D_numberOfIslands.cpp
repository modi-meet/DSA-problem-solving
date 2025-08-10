// Find the number of islands
// Given a grid of size n*m consisting of '0's (Water) and '1's (Land). Find the number of islands.
// Condition: An island is formed by connecting adjacent lands in only 4 directions(vertical & horizontal).

// DFS Solution
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& seen){
        int n = grid.size();
        int m = grid[0].size();
        seen[row][col] = 1;

        // for directional checks
        int rowDir[4] = {-1, 1, 0, 0};
        int colDir[4] = {0, 0, -1, 1};

        // pushing neighbours to queue
        for(int k = 0; k<4; k++){
            int nrow = row + rowDir[k];
            int ncol = col + colDir[k];

            if(nrow >= 0 && nrow < n && ncol < m && ncol >= 0){
                if(grid[nrow][ncol] == '1' && seen[nrow][ncol] == 0){ // is land and unseen
                    seen[nrow][ncol] = 1;
                    dfs(nrow, ncol, grid, seen);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        vector<vector<int>> seen(n, vector<int> (m,0));
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == '1' && seen[row][col] == 0){ // is land and not seen
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


// BFS Solution
class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& seen){
        int n = grid.size();
        int m = grid[0].size();
        seen[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});

        // for directional checks
        int rowDir[4] = {-1, 1, 0, 0};
        int colDir[4] = {0, 0, -1, 1};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            // pushing neighbours to queue
            for(int k = 0; k<4; k++){
                int nrow = curr.first + rowDir[k];
                int ncol = curr.second + colDir[k];

                if(nrow >= 0 && nrow < n && ncol < m && ncol >= 0){
                    if(grid[nrow][ncol] == '1' && seen[nrow][ncol] == 0){ // is land and unseen
                        seen[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        vector<vector<int>> seen(n, vector<int> (m,0));
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == '1' && seen[row][col] == 0){ // is land and not seen
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