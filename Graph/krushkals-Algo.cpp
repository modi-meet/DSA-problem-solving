// Find minimum spanning tree

class DisjointSet { 
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int Size) {
        parent = vector<int> (Size);
        size = vector<int> (Size, 1);

        for(int i=0; i<Size; i++) parent[i] = i; // initially mark node as their own parent
    }

    int ultimateParent(int u) {
        if(u == parent[u]) return u;

        return parent[u] = ultimateParent(parent[u]); // store the new parent (for path compression)
    }

    void uniteBySize(int u, int v) { // by size
        int ultiParent_u = ultimateParent(u);
        int ultiParent_v = ultimateParent(v);

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

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });

        DisjointSet ds(V);
        int mstWt = 0;

        for(auto ed : edges){
            int w = ed[2], u = ed[0], v = ed[1];
        
            if(ds.ultimateParent(u) != ds.ultimateParent(v)) {
                mstWt += w;
                ds.uniteBySize(u, v);
            }
        }
        
        return mstWt;
    }
};

// Sort the edges with lower weights at the top
// Now iterate over edges and keep connecting components
// if the nodes are from same component, no need to connect again(it will increase the MST weight)