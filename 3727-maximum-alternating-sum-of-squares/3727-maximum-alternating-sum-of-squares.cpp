class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) < abs(b); });
        int n = nums.size();
        long long result = 0;
        int i = 0;
        for (; i < n / 2; i++) {
            result += (nums[i] * nums[i]);
        }
        for (; i < n; i++) {
            result -= (nums[i] * nums[i]);
        }
        return abs(result);
    }
};