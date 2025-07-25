class Solution {
public:
    vector<int>findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int>ans(n,n);
        stack<int>st;
        
        for(int i = 0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                ans[st.top()] = i; 
                st.pop();
            }
            // if(!st.empty()){
            //     ans[i] = st.top();
            // }
            st.push(i);
        }
        return ans;
    }
    vector<int>findPSE(vector<int>& arr){
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        
        for (int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        vector<int>NSE = findNSE(arr);
        vector<int>PSE = findPSE(arr);
        int maxi = 0;
        for(int i = 0;i<arr.size();i++){
            int area = arr[i]*(NSE[i] - PSE[i] -1);
            maxi = max(maxi,area);
        }
        return maxi;
    }
};