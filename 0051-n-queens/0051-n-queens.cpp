
class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check upper-left diagonal
        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // Check upper-right diagonal
        r = row;
        c = col;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }

        // Check same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, vector<string>& board, int n) {

        // Base case: All queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing queen in every column
        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, board, n)) {

                // Choose
                board[row][col] = 'Q';

                // Explore next row
                solve(row + 1, board, n);

                // Undo (Backtracking)
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, board, n);

        return ans;
    }
};
