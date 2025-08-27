// Bridges in Graph
// A bridge is a connection that, if removed, will make some component unable to reach some other component.
// Return all bridges in the graph in any order.
// Bridge is basically, if removed, will result into two or more components.

class Solution {
    int timer = 0;
private:
    void dfs(int node, int parent, vector<int> &low, vector<int> &time, vector<vector<int>>& adj, vector<int> &seen, vector<vector<int>>& bridges) {
        seen[node] = 1;
        time[node] = low[node] = timer;
        timer++;

        for(auto &neigh : adj[node]){
            if(neigh == parent) continue; // IMPORTANT
            
            if(seen[neigh]) {
                low[node] = min(low[node], time[neigh]); 
            } 
            else { // not seen
                dfs(neigh, node, low, time, adj, seen, bridges);

                low[node] = min(low[node], low[neigh]);
                
                // check for bridge
                if(low[neigh] > time[node]) { // will give diff component
                    bridges.push_back({neigh, node});
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> seen(n, 0);

        vector<int> low(n);
        vector<int> time(n);

        vector<vector<int>> bridges;
        dfs(0, -1, low, time, adj, seen, bridges);

        return bridges;
    }
};
// TC: O(v+2E)
// SC: O(v+2E)

/*
Go to each node:
- Enter node 
- assign time & low 
- explore children 
- update low 
- check if edge is bridge 
→ return.


We need to keep track of parent, because we don't update low for parent(IMPORTANT).
- if the node is reachable from other path than parent, then it is in the same component.
*/