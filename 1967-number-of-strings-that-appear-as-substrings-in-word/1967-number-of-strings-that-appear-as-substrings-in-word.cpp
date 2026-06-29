class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        auto check = [](const string& pattern, const string& word) -> bool {
            int m = pattern.size();
            int n = word.size();
            for (int i = 0; i + m <= n; ++i) {
                bool flag = true;
                for (int j = 0; j < m; ++j) {
                    if (word[i + j] != pattern[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
            return false;
        };

        int res = 0;
        for (const string& pattern : patterns) {
            res += check(pattern, word);
        }
        return res;
    }
};