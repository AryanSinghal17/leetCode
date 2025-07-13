class Solution {
public:
    int solve(int index1,string s1,int index2,string s2,vector<vector<int>>&dp){

        if(index1 == 0 || index2 == 0){
            return 0;
        }
        if (dp[index1][index2] != -1) return dp[index1][index2];

        if(s1[index1-1] == s2[index2-1]){
            return dp[index1][index2] = 1 + solve(index1-1,s1,index2-1,s2,dp);
        }
        int left = 0 + solve(index1-1,s1,index2,s2,dp);
        int right = 0 + solve(index1,s1,index2-1,s2,dp);

        return dp[index1][index2] = max(left,right);
    }
    int longestCommonSubsequence(string s1, string s2) {
        int index1 = s1.length();
        int index2 = s2.length();

        vector<vector<int>>dp(index1+1,vector<int>(index2+1));
        // return solve(index1,s1,index2,s2,dp);

        for(int i = 0;i<=index1;i++){
            dp[i][0] = 0;
        }

        for(int j = 0;j<=index2;j++){
            dp[0][j] = 0;
        }

        for(int i = 1;i<=index1;i++){
            for(int j = 1;j<=index2;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[index1][index2];
    }
};