class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& piles, int i, int j) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int take_i = piles[i] + min(solve(piles,i + 2, j), solve(piles,i + 1, j - 1));
        int take_j = piles[j] + min(solve(piles,i, j - 2), solve(piles,i + 1, j - 1));

        return dp[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        int sum = accumulate(begin(piles), end(piles), 0);

        int Alice_score = solve(piles, 0, n - 1);

        return Alice_score > sum / 2;
    }
};