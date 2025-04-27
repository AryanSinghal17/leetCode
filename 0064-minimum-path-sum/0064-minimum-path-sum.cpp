class Solution {
public:
    int solve(vector<vector<int>>& arr, int m, int n) {
        if (m == 0 && n == 0)
            return arr[m][n];

        if (m < 0 || n < 0)
            return INT_MAX;

        int up = solve(arr, m - 1, n);
        int left = solve(arr, m, n - 1);

        return arr[m][n] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = arr[i][j];
                else {
                    int up = arr[i][j];
                    if (i > 0)
                        up += dp[i - 1][j];
                    else
                        up = INT_MAX;

                    int left = arr[i][j];
                    if (j > 0)
                        left += dp[i][j - 1];
                    else
                        left = INT_MAX;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};