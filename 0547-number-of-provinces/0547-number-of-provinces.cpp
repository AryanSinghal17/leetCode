class Solution {
public:
    void dfs(vector<vector<int>>&adj,int u,vector<bool>&visited){
        visited[u] = true;

        for(int v = 0;v<adj.size();v++){
            if(adj[u][v] == 1 && !visited[v]){
                dfs(adj,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int u = isConnected.size();
        vector<bool>visited(u,0);
        int count = 0;
        for(int i = 0;i<u;i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};