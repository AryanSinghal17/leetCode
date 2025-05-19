class Solution {
public:
    void twoSum(vector<int>& nums,vector<vector<int>>&result,int target,int s){
        int i = s;
        int j = nums.size() -1;
        while(i<j){
            if(nums[i] + nums[j] > target) j--;
            else if(nums[i] + nums[j] <target) i++;
            else{
                result.push_back({nums[i],nums[j],-target});
                while(i<j && nums[i] == nums[i+1]) i++;
                while(i<j && nums[j] == nums[j-1]) j--;
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++){
            if(i!= 0 && nums[i] == nums[i-1]){
                continue;
            }
            twoSum(nums,result,-nums[i],i+1);
        }
        return result;
    }
};