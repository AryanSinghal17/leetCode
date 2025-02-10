class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            if(st.empty() || arr[i] > 0){
                st.push(arr[i]);
            }
            else{
                while(!st.empty() && st.top() >0 && st.top() < abs(arr[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(arr[i])){
                    st.pop();
                }
                else{
                    if(st.empty() || st.top() < 0){
                        st.push(arr[i]);
                    }
                }
            }
        }
        
        int m = st.size();
        vector<int>ans(m);
        for(int i = m-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};