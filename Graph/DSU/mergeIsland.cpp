// Making A Large Island
// Given an n x n binary matrix grid. It is allowed to change at most one 0 to be 1.
// Return the size of the largest island in grid after applying this operation. An island is a 4-directionally connected group of 1s.

class Solution {
public:
    // DSU class
    class DisjointSet { 
    public:
        vector<int> size, parent;

        DisjointSet(int Size) {
            parent = vector<int> (Size);
            size = vector<int> (Size, 1);

            for(int i=0; i<Size; i++) parent[i] = i; // initially mark node as their own parent
        }

        int ulimateParent(int u) {
            if(u == parent[u]) return u;

            return parent[u] = ulimateParent(parent[u]); // store the new parent (for path compression)
        }

        void uniteBySize(int u, int v) { // by size
            int ultiParent_u = ulimateParent(u);
            int ultiParent_v = ulimateParent(v);

            if(ultiParent_u == ultiParent_v) return;

            if(size[ultiParent_u] < size[ultiParent_v]) {
                parent[ultiParent_u] = ultiParent_v;
                size[ultiParent_v] += size[ultiParent_u]; 
            }
            else { // either u is denser or both are same; add v to u
                parent[ultiParent_v] = ultiParent_u;
                size[ultiParent_u] += size[ultiParent_v]; 
            }
        }
    };

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n*n);

        int row_d[4] = {-1,1,0,0};
        int col_d[4] = {0,0,-1,1};

        // 1. unite components
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) {
                    int id = i*n + j;

                    for(int k=0; k<4; k++){
                        int nrow = i+row_d[k];
                        int ncol = j + col_d[k];

                        if(nrow >= 0 && nrow<n && ncol >= 0 && ncol < n){
                            if(grid[nrow][ncol] == 1) {
                                int nid = n * nrow + ncol;

                                ds.uniteBySize(id, nid);
                            }
                        }
                    }
                }
            }
        }

        int total = 0;
        bool hasZero = false; // edge case

        // 2. flip 0s
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j] == 0){
                    hasZero = true; // edge case
                    int temp = 1;
                    unordered_set<int> seen;

                    for(int k=0; k<4; k++){
                        int nrow = i + row_d[k];
                        int ncol = j + col_d[k];

                        if(nrow >= 0 && nrow<n && ncol >= 0 && ncol < n){
                            if(grid[nrow][ncol] == 1) {
                                int nid = n * nrow + ncol;
                                int UPar = ds.ulimateParent(nid);

                                if(!seen.count(UPar)) { // IMPORTANT
                                    temp += ds.size[UPar];

                                    seen.insert(UPar);
                                }
                            }
                        } 
                    }

                    total = max(total, temp);
                }
            }
        }

        if(hasZero == false) {
            for(int i=0; i<n*n; i++){
                if(ds.parent[i] == i) return ds.size[i];
            }
        }

        return total;
    }
};

/*
Steps:
1. unite the components (by size - IMPORTANT)
- uniting the components by Size helps finding the denser component while converting 0 to 1.
2. Try changing all 0s to 1.
3. edge case : different neighbours belongs to same components -> leads to extra counting
4. edge case : all elements are 1s -> return size of ultimate parent
*/

// Time Complexity: O(n^2 * 4alpha)
// Space Complexity: O(n^2)