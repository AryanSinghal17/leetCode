class Solution {
public:
    void dfs(int u,vector<vector<int>>& isConnected,vector<bool>&visited){
        visited[u] = true;

        for(int i = 0;i<isConnected.size();i++){
            if(!visited[i] && isConnected[u][i] == 1){
                dfs(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n,0);
        int count = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                count++;
            }
        }
        return count;
    }
};