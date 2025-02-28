class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0) return;
        
        grid[i][j] = 0;

        dfs(grid,i,j+1); // left;
        dfs(grid,i,j-1); // right;
        dfs(grid,i+1,j) ;// up
        dfs(grid,i-1,j) ;// down
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(); // row
        m = grid[0].size(); // col

        for(int i = 0 ;i<n;i++){

            // first row
            if(grid[i][0] == 1){
                dfs(grid,i,0);
            }
            // last row
            if(grid[i][m-1] == 1){
                dfs(grid,i,m-1);
            }
        }

        for(int j = 0;j<m;j++){

            // first col
            if(grid[0][j] == 1){
                dfs(grid,0,j);
            }
            // last col
            if(grid[n-1][j] == 1){
                dfs(grid,n-1,j);
            } 
        }
        int count = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j<m ;j++){
                if(grid[i][j] == 1){
                    count++;    
                }
            }
        }
        return count;
    }
};