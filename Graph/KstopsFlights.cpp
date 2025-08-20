// Cheapest Flights Within K Stops
// There are n cities connected by some number of flights. 
// Given an array flights where flights[i] = [fromi, toi, pricei].
// Given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
// If there is no such route, return -1.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0; i<n; i++){
            for(auto &it : flights) {
                adj[it[0]].push_back({it[1], it[2]});
            }
        }

        vector<int> dist(n, INT_MAX);
        queue<tuple<int, int, int>> q; // {stops, node, distance}
        q.push({0, src, 0}); 
        dist[src] = 0;

        while(!q.empty()) {
            auto [stops, node, d] = q.front();
            q.pop();

            if(stops > k) continue;

            for(auto [adjNode, adjWt] : adj[node]) {
                if(d + adjWt < dist[adjNode] && stops <= k) {
                    q.push({stops + 1, adjNode, d + adjWt});
                    dist[adjNode] = d + adjWt;
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};
// TC: O(flights.size()) ~ O(E)
// SC: O(E + N)