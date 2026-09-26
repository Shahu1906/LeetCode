class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        int prev = 0, prevprev = 0;
        for (int i = l; i <= r; i++) {
            int steal = prevprev + nums[i];
            int skip = prev;
            int temp = max(steal, skip);
            prevprev = prev;
            prev = temp;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};