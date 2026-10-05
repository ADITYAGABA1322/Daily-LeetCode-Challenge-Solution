class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int depth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') depth++;
            else {
                depth--;
                if (s[i-1] == '(')
                    ans += pow(2 , depth);
            }
        }
        return ans;
    }
};