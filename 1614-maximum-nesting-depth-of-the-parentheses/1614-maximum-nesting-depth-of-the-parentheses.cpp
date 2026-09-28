class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi = 0, curr = 0;
        for (char ch : s) {
            if (ch == '(') {
                st.push('(');
                curr++;
            } else if (ch == ')') {
                st.pop();
                maxi = max(curr, maxi);
                curr--;
            } 
        }
        return maxi;
    }
};