class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        int n = tasks.size();

        for(int i = 0;i<n;i++){
            mp[tasks[i]]++;
        }
        int ans = 0;

        for(auto& m : mp){

            if(m.second == 1){
                return -1;
            }

            ans += ceil((double)m.second/3);
        }
        return ans;
    }
};