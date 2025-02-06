class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int i = 0;
        int j = arr.size()-1;

        while(i<j){
            int sum = arr[i] + arr[j];

            if(sum > target) j--;
            else if(sum < target) i++;
            else return {i+1,j+1};
        }
        return {};
    }
};
