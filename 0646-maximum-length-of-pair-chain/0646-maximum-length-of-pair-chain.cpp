class Solution {
public:
    int solve(vector<vector<int>>&nums,int n,int i,int p,vector<vector<int>>& dp){
        if(i>= n){
            return 0;
        }
        if(p != -1 && dp[i][p] != -1) return dp[i][p];
        int take = INT_MIN;
        if(p == -1 || nums[p][1] < nums[i][0]){
            take = 1 + solve(nums,n,i+1,i,dp);
        }
        int skip = 0 + solve(nums,n,i+1,p,dp);
        if(p != -1){
            dp[i][p] =  max(take,skip);
        }
        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(pairs,n,0,-1,dp);
    }
};