// class Solution {
// public:
//     int matrixSum(vector<vector<int>>& nums) {
//         int n = nums.size();
//         int m  = nums[0].size();

//         for(auto& row: nums){
//             sort(row.begin(),row.end());
//         }

//          int sum = 0;
//         for (int i = 0; i < m; i++) {
//             sum += nums[n - 1][i];        
//         }
//         return sum;
//     }
// };

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        for (auto& row : nums) {
            sort(row.begin(), row.end());
        }

        int sum = 0;

        for (int col = 0; col < m; col++) {
            int maxVal = 0;
            for (int row = 0; row < n; row++) {
                maxVal = max(maxVal, nums[row][col]);
            }
            sum += maxVal;
        }

        return sum;
    }
};
