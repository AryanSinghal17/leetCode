class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&res,int idx,vector<int>& nums){
            ans.push_back(res);
        
        for(int i = idx ;i<nums.size();i++){
            if(i>idx && nums[i] == nums[i-1]){
                continue;
            }
        res.push_back(nums[i]);  
        solve(ans, res, i + 1, nums);  
        res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(nums.begin(),nums.end());
        solve(ans,res,0,nums);
        return ans;
    }
};