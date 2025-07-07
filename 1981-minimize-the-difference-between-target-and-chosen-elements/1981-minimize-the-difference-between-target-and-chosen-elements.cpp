class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& mat, int target, int i,
              int sum, vector<vector<int>>& dp) {
        if (i == m) {
            return abs(sum - target);
        }
        if (dp[i][sum] != -1)
            return dp[i][sum];

        int mindiff = INT_MAX;
        for (int j = 0; j < n; j++) {
            mindiff = min(mindiff,
                          solve(m, n, mat, target, i + 1, sum + mat[i][j], dp));
        }
        return dp[i][sum] = mindiff;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int maxSum = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                maxSum += mat[i][j];
            }
        }

        vector<vector<int>> dp(m, vector<int>(maxSum+1 + 1, -1));
        return solve(m, n, mat, target, 0, 0, dp);
    }
};