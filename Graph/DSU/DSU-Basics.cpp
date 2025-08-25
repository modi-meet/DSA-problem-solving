#include<iostream>
#include<vector>
using namespace std;

// Disjoint by rank
class DisjointSet { 
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
public:
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

int main() {
    DisjointSet ds(8);

    ds.unite(1, 2);
    ds.unite(2, 3);
    ds.unite(4, 5);
    ds.unite(6, 7);
    ds.unite(5, 6);
    // check if 3 and 7 have same parent or not
    if(ds.ulimateParent(3) == ds.ulimateParent(7)) cout << "Same\n";
    else cout << "Not same!\n";

    ds.unite(3, 7);
    if(ds.ulimateParent(3) == ds.ulimateParent(7)) cout << "Same\n";
    else cout << "Not same!\n";

    DisjointSet ds2(8);
    ds2.uniteBySize(1, 2);
    ds2.uniteBySize(2, 3);
    ds2.uniteBySize(4, 5);
    ds2.uniteBySize(6, 7);
    ds2.uniteBySize(5, 6);
    // check if 3 and 7 have same parent or not
    if(ds2.ulimateParent(3) == ds2.ulimateParent(7)) cout << "Same\n";
    else cout << "Not same!\n";

    ds2.uniteBySize(3, 7);
    if(ds2.ulimateParent(3) == ds2.ulimateParent(7)) cout << "Same\n";
    else cout << "Not same!\n";


    return 0;
}
// Time Complexity: O(4 * alpha) ~ O(1)

/*
 OUTPUT : 
Not same!
Same
Not same!
Same
*/


/*
(aka Union Find)

OPERATION:
1. Union - combine two sets
2. Find - tell if two nodes belongs to same set/component or not.

TYPES OF UNION:
1. union by rank,
2. union by size.

*/

// DSU BASIC IDEA:
// Consider every edge as a set (e.g. [2,4] = S1 = {2,4})
// Now, there will multiple edges connection nodes.
// If the edge contains vertices from different sets, then perform Union. (e.g. [2,4], [1,4] => S3 = (s1) U (S2) = {1,2,4})

// DSU DATA STRUCTRUE
// How to perform union grahically,
// Connect a child node to a parent node. And similarly, to connect/to perform union, we add lower ranked component(child) to higher ranked component(parent).

// HOW TO DETECT CYCLE?
// We actually don't need to perform union operation mathematically.
// BASIC - Generally, DSU is used to detect cycle, So if two vertices belongs the same set; cycle detected.
// GRAPHICAL - if the ultimate parent node are same; cycle detected.
// ARRAY - check for child's(i) parent's(arr[i]) parent(arr[arr[i]]).... if their parents turns out to be same; cycle detected.

// PATH COMPRESSION (collapsing find)
// Instead of going/relying on parent's parent series (time consuming),
// We can dirently join sub-children to their Ultimate parent. Because it is their ultimate parent & we use ultimate parent to detect the cycle.
// Graphically, we can directly connect sub-child to their ultimate parent.
// Hence, reducing the time by providing direct look up to ultimate parent in constant time.