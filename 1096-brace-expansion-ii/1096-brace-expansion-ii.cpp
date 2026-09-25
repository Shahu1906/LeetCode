class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> result;
        
        // If we are inside {...}, we need to union expressions
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {
            
            if (s[i] == '{') {
                i++; // skip '{'
                
                set<string> inside = parse(s, i);
                
                i++; // skip '}'
                
                current = combine(current, inside);
            }
            else if (s[i] == ',') {
                // Union current result into final result
                result.insert(current.begin(), current.end());
                
                current = {""};
                i++;
            }
            else {
                // Single character
                set<string> ch = {string(1, s[i])};
                
                current = combine(current, ch);
                i++;
            }
        }

        // Add the last expression
        result.insert(current.begin(), current.end());

        return result;
    }

    set<string> combine(set<string> &A, set<string> &B) {
        set<string> result;

        for (string a : A) {
            for (string b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};