// Pacific Atlantic Water Flow
class Solution {
    int n, m;
    int row_d[4] = {-1,1,0,0};
    int col_d[4] = {0,0,-1,1};
    vector<vector<int>> ans;

private:
    void dfs(int i, int j, vector<vector<int>>& ocean, vector<vector<int>>& ht) {
        ocean[i][j] = 1;

        for(int k=0; k<4; k++){
            int ni = i + row_d[k];
            int nj = j + col_d[k];

            if(ni>=0 && ni<m && nj>=0 && nj<n && !ocean[ni][nj])  // not seen
               if(ht[ni][nj] >= ht[i][j]) {
                dfs(ni, nj, ocean, ht);
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        m = ht.size();
        n = ht[0].size();
        vector<vector<int>> pacific(m, vector<int>(n,0));
        vector<vector<int>> atlantic(m, vector<int>(n,0));

        // DFS from Pacific borders
        for(int i=0; i<m; i++) dfs(i, 0, pacific, ht);
        for(int j=0; j<n; j++) dfs(0, j, pacific, ht);

        // DFS from Atlantic borders
        for(int i=0; i<m; i++) dfs(i, n-1, atlantic, ht);
        for(int j=0; j<n; j++) dfs(m-1, j, atlantic, ht);

        // intersection
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }

        return ans;        
    }
};
// TC: O(n*m)
// SC: O(n*m)

// climb up from the ocean
// instead of going to each cell and then traversing, 
//      - start traversal from the borders and mark all infected cells with their respected ocean!

// pacific ocean is all over -> 0th row & 0th column
// atlantic ocean is all over -> mth row, nth column