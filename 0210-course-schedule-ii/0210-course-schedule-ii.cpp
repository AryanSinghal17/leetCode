class Solution {
public:
    vector<int> topologicalSort(int n, unordered_map<int, vector<int>>& adj,vector<int>& indegree) {
        // Your code here
        queue<int> q;
        // 2 which node has 0 indegree push in to queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        // 3 now simple bfs
        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for (int v : adj[front]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (ans.size() != n)
            return {};

        return ans;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0); // kahan

        // make grapgh
        for (auto& vec : pre) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            // 1 make indegree
            indegree[a]++;
        }

        return topologicalSort(n, adj, indegree);
    }
};