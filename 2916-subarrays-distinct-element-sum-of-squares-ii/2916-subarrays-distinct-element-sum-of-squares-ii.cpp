
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        long long v = val % MOD;

        tree[node].sq = (
            tree[node].sq + 2 * v * tree[node].sum
            + len * v % MOD * v
        ) % MOD;

        tree[node].sum = (
            tree[node].sum + len * v
        ) % MOD;

        tree[node].lazy = (tree[node].lazy + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long v = tree[node].lazy;

        apply(node * 2, l, mid, v);
        apply(node * 2 + 1, mid + 1, r, v);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum = (
            tree[node * 2].sum +
            tree[node * 2 + 1].sum
        ) % MOD;

        tree[node].sq = (
            tree[node * 2].sq +
            tree[node * 2 + 1].sq
        ) % MOD;
    }

    void add(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l || ql > qr)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);
        int mid = l + (r - l) / 2;

        add(node * 2, l, mid, ql, qr);
        add(node * 2 + 1, mid + 1, r, ql, qr);

        pull(node);
    }

    void setOne(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node].sum = 1;
            tree[node].sq = 1;
            tree[node].lazy = 0;
            return;
        }

        push(node, l, r);
        int mid = l + (r - l) / 2;

        if (idx <= mid)
            setOne(node * 2, l, mid, idx);
        else
            setOne(node * 2 + 1, mid + 1, r, idx);

        pull(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int p = last.count(nums[j]) ? last[nums[j]] : -1;

            add(1, 0, n - 1, p + 1, j - 1);
            setOne(1, 0, n - 1, j);

            ans = (ans + tree[1].sq) % MOD;
            last[nums[j]] = j;
        }

        return ans;
    }
};
