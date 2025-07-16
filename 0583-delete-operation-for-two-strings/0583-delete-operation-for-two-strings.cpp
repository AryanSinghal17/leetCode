class Solution {
public:
    int lcs(string &word1, string &word2,int s1,int s2,vector<vector<int>>&dp){
        if(s1<0 || s2 < 0) return 0;

        if(dp[s1][s2] != -1) return dp[s1][s2];

        int take = 0;
        if(word1[s1] == word2[s2]){
            return take = 1 +  lcs(word1,word2,s1-1,s2-1,dp);
        }
        else{
            int left = lcs(word1,word2,s1-1,s2,dp);
            int right = lcs(word1,word2,s1,s2-1,dp);
            return dp[s1][s2] = max(left,right);
        }
    }
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        int s1 = word1.length();
        int s2 = word2.length();

        vector<vector<int>>dp(s1+1,vector<int>(s2+1,-1));
        int ans = lcs(word1,word2,s1-1,s2-1,dp);
        return (s1-ans) + (s2-ans);
    }
};