class Solution {
public:
    vector<vector<int>> dir { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> result(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {

                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int i = front.first;
            int j = front.second;

            for (auto& d : dir) {

                int i_ = i + d[0];
                int j_ = j + d[1];

                if(i_ >= 0 && i_<n && j_>=0 && j_<m && result[i_][j_] == -1){
                   result[i_][j_] = result[i][j] + 1;
                   q.push({i_,j_});
                }
            }
        }
        return result;
    }
};