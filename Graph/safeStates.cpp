// Find Eventual Safe States
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

class Solution {
private: 
    bool dfs(int node, vector<int>& seen, vector<int>& pathSeen, vector<int>& isSafe, vector<vector<int>>& adj) {
        seen[node] = 1;
        pathSeen[node] = 1;

        isSafe[node] = 0; // call made & may have outgoing nodes

        for(auto neighbour : adj[node]){
            if(!seen[neighbour]){ // not seen
                if(dfs(neighbour, seen, pathSeen, isSafe, adj) == true){ // cycle detected 
                    isSafe[neighbour] = 0;
                    return true;
                }
            }
            else { // already seen
                if(pathSeen[neighbour] == 1){
                    isSafe[neighbour] = 0; // not a safe node; cycle detected
                    return true;
                }
            }
        }

        isSafe[node] = 1;
        pathSeen[node] = 0;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> seen(n, 0);
        vector<int> pathSeen(n, 0);

        vector<int> isSafe(n, 0); // marking nodes that are safe

        for(int i=0; i<n; i++){
            if(!seen[i]) dfs(i, seen, pathSeen, isSafe ,adj);
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(isSafe[i]) ans.push_back(i);            
        }

        return ans;
    }
};
// Time Complexity: O(V + E)
// Space Complexity: O(V)

// BFS
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<vector<int>> adjRev(n);
        vector<int> inDegree(n);

        for(int u=0; u<n; u++){
            for(auto v : adj[u]) {
                adjRev[v].push_back(u);
                inDegree[u]++;
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto neighbour : adjRev[node]){
                inDegree[neighbour]--;

                if(inDegree[neighbour] == 0) q.push(neighbour);
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};


// If there is a cycle in a graph then there exist no terminal nodes.
// To check for cycle present or not:
// 1. DFS, 2. BFS(Khan's Algo) (Topological Sort)

// The kahn's algo pushes nodes to queue, whose inDegree is zero.
// Whereas, the terminal node has zero outDegree. Hence, changes edge direction helps solving the problem using kahn's algorithm.
