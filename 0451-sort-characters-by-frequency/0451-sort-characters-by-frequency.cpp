class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>f;

        for(char c: s){
            f[c]++;
        }

        priority_queue<pair<int,char>>pq; 

        for(auto x:f){
            pq.push({x.second,x.first});
        }

        string ans = "";
        while(!pq.empty()){
            ans = ans + string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return ans;
    }
};