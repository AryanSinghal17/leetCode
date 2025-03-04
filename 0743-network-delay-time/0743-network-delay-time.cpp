class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
        int V = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);

        result[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& vec : adj[node]) {
                int adjNode = vec.first;  
                int weight = vec.second;  

                if (d + weight < result[adjNode]) {
                    result[adjNode] = d + weight;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }
        return result;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);  // Use 1-based indexing
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist = dijkstra(adj, k);

        // Find the max time among reachable nodes
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;  // Unreachable node
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
