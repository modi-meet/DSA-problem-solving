// Most Stones Removed with Same Row or Column
// Remove a stone if there eexist another stone in that row row or column.

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        int maxRow = 0, maxCol = 0;
        for(int i=0; i<n; i++){
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        int size = maxRow + maxCol + 2; 
        DisjointSet ds(size);

        unordered_set<int> seen;

        // 1. Connect components
        for(auto &it : stones){
            int x = it[0];
            int y = maxRow + it[1] + 1; // IMPORTANT

            ds.unite(x, y);

            seen.insert(x);
            seen.insert(y);
        }

        // 2. Find Unique components
        int components = 0;
        for(auto node : seen){
            if(ds.ultimateParent(node) == node) components++;
        }
        // unique parent = no. of components
        
        return n - components;
    }
};

// consider rows & columns as nodes of a graph. 
// conneceting the given nodes gives different componenets.
// in a component(of size n), at max n-1 nodes can be removed. last node cannot be removed as it will not have any stone in row/column.
// iterate over given stones, connect nodes if they are on same row/column(+ sign)
// the answer(no. of stones that can be removed) will be, n - #components  