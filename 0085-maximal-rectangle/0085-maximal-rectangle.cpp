class Solution {
public:
    vector<int> getNSR(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            ans[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return ans;
    }


 vector<int> getNSL(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            ans[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int findArea(vector<int>& height) {
        int n = height.size();
        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);
        vector<int> width(n);

        for (int i = 0; i < n; i++) {
            width[i] = NSR[i] - NSL[i] - 1;
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, height[i] * width[i]);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& arr) {
        if (arr.empty()) return 0;
        int m = arr.size();
        int n = arr[0].size();

        vector<int>height(n);
        for(int i = 0;i<n;i++){
            height[i] = (arr[0][i] == '1') ? 1:0;
        }

        int maxArea = findArea(height);

        for(int row = 1;row<m;row++){
            for(int col = 0;col<n;col++){
                if(arr[row][col] == '0'){
                    height[col] = 0;
                }else{
                    height[col] += 1;
                }
            }
            maxArea = max(maxArea,findArea(height));
        }
        return maxArea;
    }
};