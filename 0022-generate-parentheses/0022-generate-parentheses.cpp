class Solution {
public:
    vector<string> result;

    void solve(string s, int open, int close, int n) {
        // We have used all n pairs
        if (s.length() == 2 * n) {
            result.push_back(s);
            return;
        }

        // We can add '(' if we haven't used all n opening brackets
        if (open < n) {
            solve(s + "(", open + 1, close, n);
        }

        // We can add ')' only if there are unmatched '('
        if (close < open) {
            solve(s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return result;
    }
};