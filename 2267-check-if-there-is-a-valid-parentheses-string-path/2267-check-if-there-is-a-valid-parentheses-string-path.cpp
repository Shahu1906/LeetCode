class Solution {
public:
    int m, n;
    int dp[101][101][201];

    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {

        balance += (grid[i][j] == '(') ? 1 : -1;

        if (balance < 0)
            return false;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        if (i == m - 1 && j == n - 1)
            return dp[i][j][balance] = (balance == 0);

        if (i + 1 < m) {
            if (solve(i + 1, j, balance, grid))
                return dp[i][j][balance] = true;
        }

        if (j + 1 < n) {
            if (solve(i, j + 1, balance, grid))
                return dp[i][j][balance] = true;
        }

        return dp[i][j][balance] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        if ((m + n - 1) % 2 == 1)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        return solve(0, 0, 0, grid);
    }
};