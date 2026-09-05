class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // suffixMin[i] = minimum element from i to n-1
        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        // Maximum from nums[0..i]
        int maxLeft = nums[0];

        for (int i = 0; i < n; i++) {
            maxLeft = max(maxLeft, nums[i]);

            int instability = maxLeft - suffixMin[i];

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
};