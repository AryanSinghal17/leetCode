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
        
        return solve(m-1,n-1,grid,dp);
    }
};