class Solution {
public:
    struct Node {
        int l, r, w, idx;
    };

    vector<Node> a;
    vector<vector<long long>> dp;
    vector<vector<vector<int>>> path;
    vector<int> nxt;
    int n;

    // Returns the first interval whose starting point > current r
    int getNext(int r) {
        int lo = 0, hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (a[mid].l > r)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }

    bool lexSmaller(const vector<int>& x, const vector<int>& y) {
        if (y.empty())
            return !x.empty();

        return x < y;
    }

    pair<long long, vector<int>> solve(int i, int k) {
        if (i >= n || k == 0)
            return {0, {}};

        if (dp[i][k] != -1)
            return {dp[i][k], path[i][k]};

        // Option 1: skip this interval
        auto skip = solve(i + 1, k);

        // Option 2: take this interval
        auto takeNext = solve(nxt[i], k - 1);

        long long takeScore = a[i].w + takeNext.first;

        vector<int> takePath;
        takePath.push_back(a[i].idx);

        for (int x : takeNext.second)
            takePath.push_back(x);

        // Sort indices because answer must be lexicographically
        // compared by original interval indices.
        sort(takePath.begin(), takePath.end());

        long long bestScore;
        vector<int> bestPath;

        if (takeScore > skip.first) {
            bestScore = takeScore;
            bestPath = takePath;
        }
        else if (takeScore < skip.first) {
            bestScore = skip.first;
            bestPath = skip.second;
        }
        else {
            bestScore = takeScore;

            if (takePath < skip.second)
                bestPath = takePath;
            else
                bestPath = skip.second;
        }

        dp[i][k] = bestScore;
        path[i][k] = bestPath;

        return {bestScore, bestPath};
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        a.clear();

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting point
        sort(a.begin(), a.end(), [](const Node& x, const Node& y) {
            if (x.l != y.l)
                return x.l < y.l;
            return x.r < y.r;
        });

        // Find next compatible interval
        nxt.resize(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = getNext(a[i].r);
        }

        // At most 4 intervals
        dp.assign(n, vector<long long>(5, -1));
        path.assign(n, vector<vector<int>>(5));

        return solve(0, 4).second;
    }
};