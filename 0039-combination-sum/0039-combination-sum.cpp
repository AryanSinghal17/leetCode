class Solution {
public:
    void helper(vector<int>& arr, int k,vector<vector<int>>&ans,vector<int>&res,int i){
        if(i == arr.size()){
            if(k == 0){
                ans.push_back(res);
            }
            return;
        }
        if(arr[i] <= k){
            res.push_back(arr[i]);
            helper(arr,k-arr[i],ans,res,i);
            res.pop_back();
        }
        helper(arr,k,ans,res,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>>ans;
        vector<int>res;
        helper(arr,k,ans,res,0);
        return ans;
    }
};