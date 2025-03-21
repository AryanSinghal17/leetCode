class Solution {
public:
    int solve(int ind, int buy, vector<int>& arr, int n,
              vector<vector<int>>& dp) {
        if (ind == n)
            return 0;
        int profit = 0;
        // buy
        if (buy) {
            profit = max(-arr[ind] + solve(ind + 1, 0, arr, n, dp),
                         solve(ind + 1, 1, arr, n, dp));
        } else {
            profit = max(arr[ind] + solve(ind + 1, 1, arr, n, dp),
                         solve(ind + 1, 0, arr, n, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-arr[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                } else {
                    profit = max(arr[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};