// Kosaraju's Algorithm
// Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.

class Solution {
  private:
    void dfs1(int node, stack<int>& st, vector<int>& seen, vector<vector<int>> &adj) {
        seen[node] = 1;
        
        for(auto &neighbour : adj[node]) {
            if(!seen[neighbour]) dfs1(neighbour, st, seen, adj);
        }
        
        st.push(node);
    }
    
    void dfs2(int node, vector<int>& seen, vector<vector<int>> &adjR) {
        seen[node] = 1;
        
        for(auto &neighbour : adjR[node]) {
            if(!seen[neighbour]) dfs2(neighbour, seen, adjR);
        }
    }
    
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        
        stack<int> st;
        vector<int> seen(V, 0);
        
        // 1. Store in finishing-time order
        for(int u=0; u<V; u++) {
            if(!seen[u]) dfs1(u, st, seen, adj);
        }
            
        vector<vector<int>> adjR(V);
        
        // 2. Reverse the edges
        for(int u=0; u<V; u++){
            for(auto &v : adj[u]){
                adjR[v].push_back(u);
            }
        }
        
        int SCC = 0;
        fill(seen.begin(), seen.end(), 0);
        
        // 3. count components
        while(!st.empty()) {
            int node = st.top(); 
            st.pop();
            
            if(!seen[node]) {
                SCC++;
                dfs2(node, seen, adjR);
            }
        }
        
        return SCC;
    }
};
// Time Complexity: O(V + E)
// Space Complexity: O(V)

// Steps:
/*
1. Store all the nodes in their finishing-time order. (from node 0 to last node)
2. Reverse the edges of the graph.
    - In order to count the SCCs the nromal edges leads to sneak in another component
    - Hence, reversing the edges stops it, as the SCCs will be in a cycle.
    - So, SCCs remain same but only the edge between them gets reversed. (no connection b/w two SCCs)
3. Count SCC from the new graph
*/