class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;

        for(int i = 0;i<k;i++){
            pq.push({abs(arr[i] - x),i});
        }

        for(int i = k;i<arr.size();i++){
            int diff = abs(arr[i] -x);
            if(pq.top().first > diff){
                pq.pop();
                pq.push({diff,i});
            }
        }
        vector<int>ans;
        for(int i = 0;i<k;i++){
            ans.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};