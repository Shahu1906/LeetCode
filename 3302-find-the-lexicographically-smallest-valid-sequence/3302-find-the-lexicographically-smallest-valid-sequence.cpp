class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> X(n + 1, 0);
        int i = n - 1, j = m - 1, Z = 0;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                Z++;
                j--;
            }
            X[i] = Z;
            i--;
        }
        vector<int> seq;
        i = 0, j = 0;
        bool change = true;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if ((change == true) && (X[i + 1] >= (m - j - 1))) {
                seq.push_back(i);
                change = false;
                j++;
            }
            i++;
        }
        return j == m ? seq : vector<int>();
    }
};