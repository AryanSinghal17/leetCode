class Solution {
public:
    int bsearch(int idx,vector<int>& nums,int k, vector<long>&prefixSum){
        int l = 0;
        int r = idx;
        int result = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            long count = idx - mid+1;

            long windowSum = count * nums[idx];
            long orginalSum = prefixSum[idx] - prefixSum[mid] +nums[mid];

            int ops = windowSum - orginalSum;

            if(ops > k){
                l =  mid+1;
            }else{
                result = mid;
                r = mid-1;
            }
        }
        return idx-result+1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<long>prefixSum(n);
        prefixSum[0] =  nums[0];

        for(int i = 1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int result = 1;
        for(int i = 0;i<n;i++){
            int freq = bsearch(i,nums,k,prefixSum);
            result = max(freq,result);
        }
        return result;
    }
};