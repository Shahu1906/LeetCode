class Solution {
public:
    vector<vector<int>> result;
    void sub(vector<int>& nums, int index, vector<int> curr) {
        if (index == nums.size()) {
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        sub(nums, index + 1, curr);
        curr.pop_back();
        sub(nums, index + 1, curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        sub(nums, 0, curr);
        return result;
    }
};