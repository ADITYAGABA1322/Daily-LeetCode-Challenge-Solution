class Solution {
public:
        int maxDepth(string s) {
        int res = 0, cur = 0;
        for (char& c: s) {
            if (c == '(')
                res = max(res, ++cur);
            if (c == ')')
                cur--;
        }
        return res;
    }
};