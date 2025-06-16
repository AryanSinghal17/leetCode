class Solution {
public:
    bool topoSort(unordered_map<int,vector<int>>& adj,int n,vector<int>&indegree){
        queue<int>q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;

            for(auto &v : adj[front]){
                
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
       return (count == n) ;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0); // kahan

        // make grapgh
        for(auto &vec :pre){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            // 1 make indegree
            indegree[a]++;
        }

         return topoSort(adj,n,indegree);
    }
};