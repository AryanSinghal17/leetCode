class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0;
        if( n == nums.size()){
            return n;
        }
        for(int i = 1;i<nums.size();i++){
            if(nums[n] != nums[i]){
                n++;
                nums[n] = nums[i];
            }
        }
        return n+1;
    }
};