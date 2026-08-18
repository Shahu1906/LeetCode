class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;

        for (int i = k, j = 0; i <= n; i++, j++) {
            set<int> st;
            for (int l = j; l < i; l++) {
                st.insert(nums[l]);
            }
            for (int x : st)
                mp[x]++;
        }

        int ans = -1;
        for (auto [x, freq] : mp) {
            if (freq == 1) {
                ans = max(ans, x);
            }
        }
        return ans;
    }
};