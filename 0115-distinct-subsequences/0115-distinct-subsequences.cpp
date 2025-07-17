class Solution {
public:
    int solve(int i,int j,string& s,string& t,vector<vector<int>>&dp){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        }else{
            return dp[i][j] = solve(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int i = s.length();
        int j = t.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return solve(i-1,j-1,s,t,dp);
    }
};