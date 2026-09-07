class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        vector<long long> dp(s.length() + 1, 0);

        // Empty subsequence
        dp[0] = 1;

        vector<long long> last(26, 0);

        for (int i = 1; i <= s.length(); i++) {

            int c = s[i - 1] - 'a';

            // Double all previous subsequences
            dp[i] = (2 * dp[i - 1]) % MOD;

            // Remove duplicates created by this character
            dp[i] = (dp[i] - last[c] + MOD) % MOD;

            // Store the old number of subsequences
            last[c] = dp[i - 1];
        }

        // Remove empty subsequence
        return (dp[s.length()] - 1 + MOD) % MOD;
    }
};