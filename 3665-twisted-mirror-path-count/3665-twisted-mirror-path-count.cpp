class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> R(m, vector<int>(n, 0)), D(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    long long rest = (long long)R[i][j] + D[i][j] + ((i == 0 && j == 0) ? 1 : 0);
                    rest %= MOD;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + rest) % MOD;
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + rest) % MOD;
                } else {
                    // entered moving right -> deflected down
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + R[i][j]) % MOD;
                    // entered moving down -> deflected right
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + D[i][j]) % MOD;
                }
            }
        }

        return ((long long)R[m - 1][n - 1] + D[m - 1][n - 1]) % MOD;
    }
};