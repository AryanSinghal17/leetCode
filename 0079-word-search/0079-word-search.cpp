class Solution {
public:
    int n,m;
    bool find(int i,int j,vector<vector<char>>& board,string word,int idx){
        if(idx == word.length()){
            return true;
        }

        if(i >= n || j >= m || i < 0 || j < 0 || board[i][j] != word[idx]) {
        return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';

        bool found = find(i + 1, j, board, word, idx + 1) || find(i - 1, j, board, word, idx + 1) ||find(i, j + 1, board, word, idx + 1) ||
                     find(i, j - 1, board, word, idx + 1);

        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        n = board.size();
        m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0] && find(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};