class Solution {
public:
    void solve(vector<int>&arr,int targert,vector<vector<int>>&ans,vector<int>res,int idx){
        if(targert <0){
            return;
        }
        if(targert == 0){
            ans.push_back(res);
            return;
        }

        for(int i = idx;i<arr.size();i++){
            if(i> idx && arr[i] == arr[i-1]){
                continue;
            }
            res.push_back(arr[i]);
            solve(arr,targert-arr[i],ans,res,i+1);
            res.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>res;

        solve(arr,target,ans,res,0);
        return ans;
    }
};