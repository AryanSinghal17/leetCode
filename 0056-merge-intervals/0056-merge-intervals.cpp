class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>result;

        sort(intervals.begin(),intervals.end());

        result.push_back(intervals[0]);

        for(int i = 1;i<n;i++){
            if(intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};