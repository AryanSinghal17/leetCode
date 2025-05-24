class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int id = 0;
        int top = 0;
        int bottom = n - 1;

        int left = 0;
        int right = n - 1;
        int idx = 1;

        while (top <= bottom && left <= right) {

            if (id == 0) {
                for (int i = left; i <= right; i++) {
                    ans[top][i] = idx++;
                }
                top++;
                id++;
            }

            if (id == 1) {
                for (int i = top; i <= bottom; i++) {
                    ans[i][right] = idx++;
                }
                right--;
                id++;
            }

            if (id == 2) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = idx++;
                }
                bottom--;
                id++;
            }
            if (id == 3) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = idx++;
                }
                left++;
                id = 0;
            }
        }
        return ans;
    }
};