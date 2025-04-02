class Solution {
public:
    int solve(vector<int>&nums,int i,int p,int n,vector<vector<int>>&dp){
        if(i >= n) return 0;
        int take = INT_MIN;
        if(p != -1 && dp[i][p] != -1) return dp[i][p];
        
        if(p == -1 || nums[p] < nums[i]){
            take = 1 + solve(nums,i+1,i,n,dp);
        }
        int skip = 0 + solve(nums,i+1,p,n,dp);
        if(p != -1){
            dp[i][p] =  max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solve(nums,0,-1,n,dp); 
    }
};