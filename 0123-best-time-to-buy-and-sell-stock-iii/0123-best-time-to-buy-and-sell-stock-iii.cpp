class Solution {
public:
    int solve(int ind,int buy,int cap,vector<int>&arr,int n,vector<vector<vector<int>>>&dp){
        if(ind == n || cap == 0) return 0;

        int profit = 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if (buy) {
            profit = max(-arr[ind] + solve(ind + 1, 0,cap, arr, n,dp),
                         solve(ind + 1, 1,cap,arr, n,dp));
        } else {
            profit = max(arr[ind] + solve(ind + 1, 1,cap-1, arr, n,dp),
                         solve(ind + 1, 0,cap,arr, n,dp));
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3, vector<int>(3, -1)));

        return solve(0,1,2,prices,n,dp);
    }
};