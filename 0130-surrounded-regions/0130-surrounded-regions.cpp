class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool valid(int m, int n, int row, int col) {
        if (row >= 0 && col >= 0 && row < m && col < n) {
            return true;
        }
        return false;
    }
    void valid(vector<vector<char>>& board, int row, int col) {
        board[row][col] = '#';
        for (int k = 0; k < 4; k++) {
            int nrow = row + x[k];
            int ncol = col + y[k];
            if (valid(board.size(), board[0].size(), nrow, ncol) &&
                board[nrow][ncol] == 'O') {
                valid(board, nrow, ncol);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // Front Row
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                valid(board, 0, i);
            }
        }
        // Last Row
        for (int i = 0; i < n; i++) {
            if (board[m - 1][i] == 'O') {
                valid(board, m - 1, i);
            }
        }
        // FIRST Column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                valid(board, i, 0);
            }
        }
        // Last Column
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O') {
                valid(board, i, n - 1);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};