class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int x : nums)
            mp[x]++;
        int i = 1;
        auto it = mp.begin();
        while (true) {
            if (mp[k * i] == 0)
                return k * i;
            else
                i++;
            it++;
        }
        return -1;
    }
};