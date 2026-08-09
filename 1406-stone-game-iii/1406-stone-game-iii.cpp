class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int a = 0, b = 0, c = 0;
        for (int i = n - 1; i >= 0; i--) {
            int result = INT_MIN;

            result = max(result, stoneValue[i] - a);

            if (i + 2 <= n)
                result = max(result, stoneValue[i] + stoneValue[i + 1] - b);
            if (i + 3 <= n)
                result = max(result, stoneValue[i] + stoneValue[i + 1] +
                                         stoneValue[i + 2] - c);

            c = b;
            b = a;
            a = result;
        }

        if (a > 0)
            return "Alice";
        else if (a < 0)
            return "Bob";
        else
            return "Tie";
    }
};