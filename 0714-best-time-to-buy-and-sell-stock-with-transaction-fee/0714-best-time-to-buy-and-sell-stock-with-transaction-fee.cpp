class Solution {
public:
    int solve(int ind, int buy, vector<int>& arr, int n,
              vector<vector<int>>& dp,int fee) {
        if (ind >= n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) {
            profit = max(-arr[ind] + solve(ind + 1, 0, arr, n, dp,fee),
                         solve(ind + 1, 1, arr, n, dp,fee));
        } else {
            profit = max(arr[ind]-fee + solve(ind + 1, 1, arr, n, dp,fee),
                         solve(ind + 1, 0, arr, n, dp,fee));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,n,dp,fee);
    }
};