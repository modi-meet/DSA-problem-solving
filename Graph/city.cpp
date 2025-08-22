// Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, 
// If there are multiple such cities, return the city with the greatest number.

// Using Floyd-Warshall Algorithm
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Build adjacency matrix 
        for(auto &ed : edges) {
            int u = ed[0], v = ed[1], wt = ed[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int i=0; i<n; i++) dist[i][i] = 0;

        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX) continue;

                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int city;
        int minCount = n;

        for(int i=0; i<n; i++){
            int count = 0;

            for(auto &num : dist[i]) {
                if(num <= distanceThreshold) {
                    count++;
                }
            }

            if(count <= minCount) {
                city = i;
                minCount = count;
            }
        }

        return city;
    }
};
// TC: O(n^3)
// SC: O(n^2)

// Usign Dijkstra's Algorithm
class Solution {
private:
    void dijkstra(int src, vector<vector<int>>& dist, vector<vector<pair<int, int>>>& adj){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src][src] = 0;

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[src][node]) continue;

            for(auto [adjNode, adjWt] : adj[node]) {
                if(d+adjWt < dist[src][adjNode]) {
                    dist[src][adjNode] = d+adjWt;
                    pq.push({d+adjWt, adjNode});
                }
            }
        }

    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        // Build adjacency list 
        for(auto &ed : edges) {
            adj[ed[0]].push_back({ed[1], ed[2]});
            adj[ed[1]].push_back({ed[0], ed[2]});
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // apply dijkstra's algorithm for each node
        for(int i=0; i<n; i++) {
            dijkstra(i, dist, adj);
        }


        int city;
        int minCount = n;

        for(int i=0; i<n; i++){
            int count = 0;

            for(auto &num : dist[i]) {
                if(num <= distanceThreshold) {
                    count++;
                }
            }

            if(count <= minCount) {
                city = i;
                minCount = count;
            }
        }

        return city;
    }
};
// Time Complexity : O(V*E*logV)
// Space Complexity : O(n^2)