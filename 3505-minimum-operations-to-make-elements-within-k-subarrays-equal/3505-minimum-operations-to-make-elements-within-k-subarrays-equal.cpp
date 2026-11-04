
class Solution {
public:
    using ll = long long;

    multiset<int> low, high;
    ll sumLow = 0, sumHigh = 0;

    void add(int x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }
        balance();
    }

    void remove(int x) {
        auto it = low.find(x);

        if (it != low.end()) {
            sumLow -= x;
            low.erase(it);
        } else {
            it = high.find(x);
            sumHigh -= x;
            high.erase(it);
        }

        balance();
    }

    void balance() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            int x = *it;

            sumLow -= x;
            low.erase(it);

            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < high.size()) {
            auto it = high.begin();
            int x = *it;

            sumHigh -= x;
            high.erase(it);

            low.insert(x);
            sumLow += x;
        }
    }

    ll getCost() {
        ll median = *low.rbegin();

        return median * (ll)low.size() - sumLow
             + sumHigh - median * (ll)high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<ll> cost(n - x + 1);

        low.clear();
        high.clear();
        sumLow = sumHigh = 0;

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = getCost();
        }

        const ll INF = LLONG_MAX / 4;

        vector<ll> prev(n + 1, 0), curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);
            curr[0] = INF;

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
