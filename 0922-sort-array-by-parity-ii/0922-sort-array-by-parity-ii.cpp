class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n =  nums.size();
        vector<int>ans;

        vector<int>even; 
        vector<int>odd; 

        for(int i = 0;i<n;i++){
            if(nums[i] %2 == 0){
                even.push_back(nums[i]);
            }else{
                odd.push_back(nums[i]);
            }
        }
        int p = 0;
        int q = 0;

        for(int i = 0;i<n;i++){
            if(i %2 == 0){
                ans.push_back(even[p]);
                p++;
            }else{
                ans.push_back(odd[q]);
                q++;
            }
        }
        return ans;
    }
};