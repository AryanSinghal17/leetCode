class Solution {
public:
    int trap(vector<int>& arr) {
        int length = arr.size();
        if (length == 0) return 0;
        int res = 0;

        int lmax[length];
        int rmax[length];

        lmax[0] = arr[0];
        for(int i = 1;i<length;i++){
            lmax[i] = max(arr[i], lmax[i - 1]);
        }
        rmax[length-1] = arr[length -1];
        for(int i = length - 2;i>=0;i--){
            rmax[i] = max(arr[i],rmax[i+1]);
        }

        for(int i = 1;i<length -1;i++){
            res = res + min(rmax[i],lmax[i]) - arr[i];
        }
        return res;
     }
};