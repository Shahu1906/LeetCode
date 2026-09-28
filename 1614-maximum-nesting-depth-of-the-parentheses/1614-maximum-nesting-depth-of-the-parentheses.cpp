class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0, curr = 0;
        for (char ch : s) {
            if (ch == '(') {
                curr++;
            } else if (ch == ')') {
                maxi = max(curr, maxi);
                curr--;
            } 
        }
        return maxi;
    }
};