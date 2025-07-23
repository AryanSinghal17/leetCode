class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>seen;
        for(auto it = s.begin(); it != s.end();it++){
            seen[*it]++;
        }
        for(int i = 0 ;i<s.length();i++){
            if(seen[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};