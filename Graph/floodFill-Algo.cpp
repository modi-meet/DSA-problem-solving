// Given a 2D grid image[][] of size n*m, where each image[i][j] represents the color of a pixel in the image. 
// Also provided a coordinate(sr, sc) representing the starting pixel (row and column) and a new color value newColor.

// Task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. 
// Two pixels are considered connected if in 4D that have the same original color.

// DFS
class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& image, vector<vector<int>>& grid, int newColor, int OGcolor){
        int n = image.size();
        int m = image[0].size();

        grid[r][c] = newColor;

        int row_dir[4] = {-1, 1, 0, 0};
        int col_dir[4] = {0, 0, -1, 1};

        for(int k=0; k<4; k++){
            int nrow = r + row_dir[k];
            int ncol = c + col_dir[k];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                if(image[nrow][ncol] == OGcolor && grid[nrow][ncol] != newColor){
                    grid[nrow][ncol] = newColor; // paint
                    dfs(nrow, ncol, image, grid, newColor, OGcolor); 
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();

        int OGcolor = image[sr][sc];
        if(newColor == OGcolor) return image;

        image[sr][sc] = newColor;
        vector<vector<int>> grid = image;

        dfs(sr, sc, image, grid, newColor, OGcolor);
        return grid;
    }
};
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)


// BFS
class Solution {
private:
    void bfs(int r, int c, vector<vector<int>>& image, vector<vector<int>>& grid, int newColor, int OGcolor){
        int n = image.size();
        int m = image[0].size();

        grid[r][c] = newColor;
        queue<pair<int,int>> q;
        q.push({r,c});

        int row_dir[4] = {-1, 1, 0, 0};
        int col_dir[4] = {0, 0, -1, 1};

        while(!q.empty()){ 
            auto curr = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int nrow = curr.first + row_dir[k];
                int ncol = curr.second + col_dir[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(image[nrow][ncol] == OGcolor && grid[nrow][ncol] != newColor){
                        grid[nrow][ncol] = newColor; // paint
                        q.push({nrow, ncol}); 
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();

        int OGcolor = image[sr][sc];
        if(newColor == OGcolor) return image;

        image[sr][sc] = newColor;
        vector<vector<int>> grid = image;

        bfs(sr, sc, image, grid, newColor, OGcolor);
        return grid;
    }
};
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)