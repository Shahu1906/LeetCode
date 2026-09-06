class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);

        int prefixMax = nums[0];

        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);
            int instab = prefixMax - suffixMin[i];

            if (instab <= k)
                return i;
        }

        return -1;
    }
};