class Solution {
    // DSU class
    class DisjointSet {
        vector<int> rank;
    public:
        vector<int> parent;
        
        DisjointSet(int Size) {
            parent = vector<int> (Size);
            rank = vector<int> (Size, 0);

            for(int i=0; i<Size; i++) parent[i] = i; // initially mark node as their own parent
        }

        int ultimateParent(int u) {
            if(u == parent[u]) return u;

            return parent[u] = ultimateParent(parent[u]); // store the new parent (for path compression)
        }

        void unite(int u, int v) { // by Rank
            int ultiParent_u = ultimateParent(u);
            int ultiParent_v = ultimateParent(v);

            if(ultiParent_u == ultiParent_v) {
                return; // both belongs to same set; cycle detected
            }
            if(rank[ultiParent_u] < rank[ultiParent_v]) { // parent will be the one with higher rank
                parent[ultiParent_u] = ultiParent_v; // update new parent
            }
            else if(rank[ultiParent_v] < rank[ultiParent_u]) {
                parent[ultiParent_v] = ultiParent_u; // update new parent
            } 
            else { // both has same rank; join v to u
                parent[ultiParent_v] = ultiParent_u;
                rank[ultiParent_u]++; // update the rank of parent
            }   
        }
    };
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> ans;
        
        vector<vector<int>> mat(n, vector<int>(m, 0));
        
        DisjointSet ds(n*m);
        int islandCnt = 0;
        
        int row_d[4] = {-1,1,0,0};
        int col_d[4] = {0,0,-1,1};
        
        for(auto &it : operators){
            int x = it[0], y = it[1];
            
            if (mat[x][y] == 1) {
                ans.push_back(islandCnt);
                continue;
            }
            
            mat[x][y] = 1;
            islandCnt++;
            
             int id = x * m + y; // IMPORTANT
            
            for(int k=0; k<4; k++){
                int nrow = x + row_d[k];
                int ncol = y + col_d[k];
                    
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(mat[nrow][ncol] == 1) {
                        int nid = nrow * m + ncol;
                        
                        if(ds.ultimateParent(id) != ds.ultimateParent(nid)) { // parent[{x,y}] != parent[{nrow, ncol}]
                            islandCnt--; // merged → reduce island count
                            ds.unite(id, nid);
                        }
                    }
                }
            }
            
            ans.push_back(islandCnt);
        }
        
     return ans;   
    }
};

/*

// Steps:
1. mark the element 1
2. increament the island count by 1.
3. check neighbours whether they are are land or not. 
    - if land, reduce the count by 1 & connect the component.
4. found another neighbour as lnd,
    - if ultimate parents are same, reduce the count by 1.
5. add the count to ans.

-> IMPORTANT:
    Mark each element of matrix as their own parent.
    the element-id will be, their respective position in the matrix. 
    (e.g.- 4x3 array, last element's id will be - 11) 

*/

// Time Complexity: O(K * 4alpha) (K - total number of operators)
// Space Complexity: O(n*m) + O(n*m) + O(n*m) (DSU's parent, rank array + matrix)