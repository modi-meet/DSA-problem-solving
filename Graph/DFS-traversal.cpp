// Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. 
// Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and 
// return a list containing the DFS traversal of the graph.

class Solution {
  private:
    void dfs(int nodeIdx, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& seen){
        ans.push_back(nodeIdx);
        seen[nodeIdx] = true;
        
        // trveerse neighbours
        for(auto it : adj[nodeIdx]){
            if(seen[it] == false) 
                dfs(it, adj, ans, seen);
        }
    }  
  
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        vector<bool> seen(adj.size(), false);
        seen[0] = true;
        
        dfs(0, adj, ans, seen);
        return ans;
    }
};
// Time Complexity: O(N) + O(2*E)
// Space Complexity: O(3*N)~O(N) (stack, seen, ans)

// For Directed-Graph- TC: O(N) + O(E)