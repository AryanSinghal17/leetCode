class Solution {
public:
    int solve(vector<int>& arr, int n, int amount, vector<vector<int>>& dp) {
        if (n == 0) {
            if (amount % arr[0] == 0)
                return amount / arr[0];
            return 1e9;
        }

        if (dp[n][amount] != -1)
            return dp[n][amount];

        int not_take = solve(arr, n - 1, amount, dp);
        int take = 1e9;
        if (arr[n] <= amount) {
            take = 1 + solve(arr, n, amount - arr[n], dp);
        }

        return dp[n][amount] = min(not_take, take);
    }
    int minimumElements(vector<int>& num, int x) {
        // Write your code here.
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(x + 1, 0));

        for (int i = 0; i <= x; i++) {
            if (i % num[0] == 0)
                dp[0][i] = i / num[0];
            else
                dp[0][i] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= x; j++) {
                int not_take = dp[i - 1][j];
                int take = 1e9;
                if (num[i] <= j) {
                    take = 1 + dp[i][j - num[i]];
                }
                dp[i][j] = min(take, not_take);
            }
        }
        int ans = dp[n - 1][x];
        if (ans >= 1e9)
            return -1;
        return ans;
    }
    int coinChange(vector<int>& arr, int amount) {
        int n = arr.size();
      

        // int ans = solve(arr,n-1,amount,dp);
        int ans = minimumElements(arr,amount);

            if (ans >= 1e9) return -1;
        return ans;
    }
};