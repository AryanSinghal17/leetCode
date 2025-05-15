class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        sort(nums.begin(),nums.end());

        int num = INT_MIN;
        int cnt = 0;
        int length = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] -1 == num){
                cnt+=1;
                num = nums[i];
            }else if(nums[i] != num){
                cnt = 1;
                num = nums[i];
            }
            length = max(length,cnt);
        }
        return length;
    }
};