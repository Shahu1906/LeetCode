class Solution {
public:
    int dp[21][21];
    int solve(vector<int>& nums, int i, int j) {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];
        if (dp[i][j] != -1)
            return dp[i][j];
        int take_i = nums[i] - solve(nums, i + 1, j);
        int take_j = nums[j] - solve(nums, i, j - 1);
        return dp[i][j] = max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(nums, 0, n - 1) >= 0;
    }
};