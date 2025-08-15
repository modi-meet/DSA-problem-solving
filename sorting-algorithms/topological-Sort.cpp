// Topological Sort

class Solution {
private: 
    void dfs(int node, vector<vector<int>>& adj, stack<int>& st, vector<int>& seen){
        seen[node] = 1;
        
        for(auto neighbour : adj[node]){
            if(!seen[neighbour]){
                dfs(neighbour, adj, st, seen);
            }
        }
        
        st.push(node); // push when no further calls can be made from current node
    }
    
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj (V);
        
        for(auto ed : edges){
            adj[ed[0]].push_back(ed[1]);
        }
        
        vector<int> seen(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!seen[i]) dfs(i, adj, st, seen);
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
// Time Complexity: O(V + E)
// Space Complexity: O(V)

// - Only applicable on DAG (Directed Asyclic Graph)