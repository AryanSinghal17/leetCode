class Solution {
public:
    vector<int>nge(vector<int>&nums2){
        
        stack<int>st;
        int n = nums2.size();
        vector<int>ans(n);

        for(int i = n-1;i>=0;i--){
            while(st.size() > 0 && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty())ans[i] = -1;
            else{
                ans[i] = st.top();
            }
            st.push(nums2[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans2 = nge(nums2);

        vector<int>ans;
        unordered_map<int,int>mp;

        for(int i = 0;i<nums2.size();i++){
            mp[nums2[i]] = ans2[i];
        }

        for(int i = 0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);

        }
        

        return ans;
    }
};