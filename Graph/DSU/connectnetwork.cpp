// Number of Operations to Make Network Connected

class Solution {
// DSU class
public:
    class DisjointSet {
        vector<int> rank;
    public:
        vector<int> parent;
        int extraEdges = 0;
        
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
                extraEdges++;
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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1; // edges < n-1 ; return false

        DisjointSet ds(n);

        // form the union
        for(auto it : connections){
            ds.unite(it[0], it[1]);
        }

        // find no. of components
        int components = 0;
        for(int i=0; i<n; i++) {
            if(ds.parent[i] == i) components++;
        }
        
        return (components-1 <= ds.extraEdges) ? (components-1) : -1; 
    }
};
// TC: O(N + M)