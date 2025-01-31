class Solution {
public:
    void solver(vector<vector<int>>& ans, vector<int>& nums, vector<int>& res, int k, int n, int idx) {
        if (k == 0 && n == 0) {
            ans.push_back(res);
            return;
        }

        if (idx >= nums.size() || k < 0 || n < 0) return;  

        res.push_back(nums[idx]);
        solver(ans, nums, res, k - 1, n - nums[idx], idx + 1);
        res.pop_back();  
        solver(ans, nums, res, k, n, idx + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> res;  
        solver(ans, nums, res, k, n, 0);
        return ans;
    }
};
