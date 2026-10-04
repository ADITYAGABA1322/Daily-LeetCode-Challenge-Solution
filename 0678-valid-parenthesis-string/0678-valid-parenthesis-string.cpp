class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;

        for (auto c : s) {
            if (c == '(') {
                lo++;
                hi++;
            }
            else if (c == ')') {
                lo--;
                hi--;
            }
            else if (c == '*') {
                lo--;
                hi++;
            }

            if (hi < 0)
                return false;

            lo = max(lo, 0);
        }

        return lo == 0;
    }
};