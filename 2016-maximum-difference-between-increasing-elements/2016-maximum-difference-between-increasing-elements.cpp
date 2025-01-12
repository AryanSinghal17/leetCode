class Solution {
public:
    int maximumDifference(vector<int>& arr) {
        int res = -1;
        int minVal = arr[0];

        for(int j = 1 ;j<arr.size();j++){
            if(arr[j] > minVal){
            res = max(res,arr[j] - minVal);
            }
            minVal = min(minVal,arr[j]);
        }

        return res;
    }
};