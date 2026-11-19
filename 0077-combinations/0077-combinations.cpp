class Solution {
public:
    vector<vector<int>> result;
    void C(int index, int n, int k, vector<int>& curr) {
        if (curr.size() == k) {
            result.push_back(curr);
            return;
        }
        for (int i = index; i < n; i++) {
            curr.push_back(i + 1);
            C(i + 1, n, k, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        C(0, n, k, curr);
        return result;
    }
};