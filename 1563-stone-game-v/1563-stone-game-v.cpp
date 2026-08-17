class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> cumsum(n + 1, 0);

        for (int i = 0; i < n; i++)
            cumsum[i + 1] = cumsum[i] + stoneValue[i];

        vector<vector<int>> t(n, vector<int>(n, 0));

        for (int l = n - 1; l >= 0; l--) {
            for (int r = l + 1; r < n; r++) {

                for (int mid = l; mid < r; mid++) {

                    int leftsum =
                        cumsum[mid + 1] - cumsum[l];

                    int rightsum =
                        cumsum[r + 1] - cumsum[mid + 1];

                    if (leftsum < rightsum) {
                        t[l][r] = max(
                            t[l][r],
                            leftsum + t[l][mid]
                        );
                    }
                    else if (rightsum < leftsum) {
                        t[l][r] = max(
                            t[l][r],
                            rightsum + t[mid + 1][r]
                        );
                    }
                    else {
                        t[l][r] = max({
                            t[l][r],
                            leftsum + t[l][mid],
                            rightsum + t[mid + 1][r]
                        });
                    }
                }
            }
        }

        return t[0][n - 1];
    }
};