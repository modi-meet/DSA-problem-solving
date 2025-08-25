class DisjointSet {
    vector<int> size;
public:
    vector<int> parent;
    
    DisjointSet(int Size) {
        rank = vector<int> (Size, 0);
        parent = vector<int> (Size);
        size = vector<int> (Size, 1);

        for(int i=0; i<Size; i++) parent[i] = i; // initially mark node as their own parent
    }

    int ulimateParent(int u) {
        if(u == parent[u]) return u;

        return parent[u] = ulimateParent(parent[u]); // store the new parent (for path compression)
    }

    void unite(int u, int v) { // by Rank
        int ultiParent_u = ulimateParent(u);
        int ultiParent_v = ulimateParent(v);

        if(ultiParent_u == ultiParent_v) return; // both belongs to same set; cycle detected
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

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DisjointSet ds(V);
        
        // O(V^2 * 4 * alpha)
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if (isConnected[i][j] == 1) {
                    ds.unite(i, j);
                }
            }
        }
        
        int prov = 0;

        // O(V * 4* alpha)
        for(int i=0; i<V; i++) {
            if(ds.parent[i] == i) prov++;
        }

        return prov;
    }
};
// TC: O(V^2)
// SC: O(V^2 + V) (adjMatrix + parent array)