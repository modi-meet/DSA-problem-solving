// Unique Paths
// Given the two integers m and n, 
// The robot is initially located at the top-left corner. 
// The robot tries to move to the bottom-right corner
// return the number of possible unique paths that the robot can take to reach the bottom-right corner.

class Solution {
    int t[102][102];
private:
    int solve(int m, int n, int i, int j){
        // Base case
        if(i == m-1 && j == n-1) return 1;
        if (i >= m || j >= n) return 0;

        if(t[i][j] != -1) return t[i][j];

        int down = solve(m, n, i+1, j);
        int right = solve(m, n, i, j+1);
        
        return t[i][j] = down + right;
    }

public:
    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        return solve(m, n, 0, 0);
    }
};
// TC : O(n*m)
// SC: O(n*m)