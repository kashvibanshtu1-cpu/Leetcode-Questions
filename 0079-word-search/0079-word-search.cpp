class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    bool valid(int i, int j, int m, int n) {
        if (i >= m || j >= n || i < 0 || j < 0) {
            return false;
        }
        return true;
    }
    bool fun(vector<vector<char>>& board, string word, int i, int j,
             int word_indx, vector<vector<bool>>& vis) {

        if (word_indx == word.size()) {
            return true;
        }
        if (!valid(i, j, board.size(), board[0].size()) || vis[i][j] ||
            board[i][j] != word[word_indx]) {
            return false;
        }
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int nrow = i + x[k];
            int ncol = j + y[k];

            if (fun(board, word, nrow, ncol, word_indx + 1, vis)) {
                vis[i][j] = false;
                return true;
            }
        }

        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (fun(board, word, i, j, 0, vis))
                    return true;
            }
        }
        return false;
    }
};