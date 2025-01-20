class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int num = 0;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] == 1){
                num++;
            }
            ans = max(num,ans);
            if(nums[i] != 1){
                num = 0;
            }
        }
        return ans;
    }
};