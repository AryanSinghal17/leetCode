class Solution {
public:
    void solve(int n,string s,vector<string>&result,int open,int close){
        if(s.length() == 2*n){
            result.push_back(s);
            return;
        }
        if(open<n){
        s.push_back('(');
        solve(n,s,result,open+1,close);
        s.pop_back();
        }
        if(close< open){
        s.push_back(')');
        solve(n,s,result,open,close+1);
        s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string s = "";
        int open = 0;
        int close =0;
        solve(n,s,result,open,close);
        return result;
    }
};