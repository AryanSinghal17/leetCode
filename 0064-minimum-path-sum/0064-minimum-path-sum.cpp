class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(m == 0 && n == 0) return grid[m][n];

        if(m < 0 || n < 0) return INT_MAX;
        if(dp[m][n] != -1) return dp[m][n];

        int up = solve(m-1,n,grid,dp);
        int left = solve(m,n-1,grid,dp);

        return dp[m][n] = grid[m][n] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up =0 ,left = 0;
                    if(i > 0) up +=dp[i-1][j];
                    else up += 1e9;
                    if(j >0 ) left += dp[i][j-1];
                    else left +=  1e9;
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};