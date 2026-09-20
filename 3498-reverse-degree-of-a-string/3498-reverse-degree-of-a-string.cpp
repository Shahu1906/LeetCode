class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            int x = 'z' - s[i] + 1;
            result += x * (i + 1);
        }
        return result;
    }
};