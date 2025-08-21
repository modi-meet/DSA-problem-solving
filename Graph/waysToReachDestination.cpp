// Number of Ways to Arrive at Destination

class Solution {
    int M = 1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        vector<int> ways(n, 0);
        ways[0] = 1;
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
        
            for(auto [adjNode, adjWt] : adj[node]) {
                if(d + adjWt < dist[adjNode]) {
                    dist[adjNode] = d+adjWt;
                    pq.push({d + adjWt, adjNode});

                    ways[adjNode] = ways[node];
                }

                else if(d+adjWt == dist[adjNode]) 
                    ways[adjNode] = (ways[adjNode] + ways[node]) % M;
            }
        }

        if(dist[n-1] == INT_MAX) return -1; // not reachable

        return ways[n-1]%M;
    }
};
// TC : O(E*logV)
// SC : O(n+m)