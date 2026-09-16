class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxSum(n);
        vector<int> minSum(n);
        maxSum[0] = nums[0];
        minSum[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            maxSum[i] = max(maxSum[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            minSum[i] = min(minSum[i + 1], nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(maxSum[i]-minSum[i]<=k)
            {
                return i;
            }
        }
        return -1;
    }
};