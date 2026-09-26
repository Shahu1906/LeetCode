class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;
        for (auto& x : knowledge) {
            mp[x[0]] = x[1];
        }
        string result = "";

        for (int i = 0; i < s.size();) {
            if (s[i] == '(') {
                i++;
                string w;
                while (s[i] != ')') {
                    w.push_back(s[i]);
                    i++;
                }
                i++;
                if (mp.find(w) != mp.end()) {
                    result += mp[w];
                } else {
                    result += "?";
                }
            } else {
                result.push_back(s[i]);
                i++;
            }
        }
        return result;
    }
};