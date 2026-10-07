class Solution {
public:

    void solve(string& s, int index,
               int openRem, int closeRem,
               int balance,
               string& curr,
               set<string>& res) {

        if (balance < 0 || openRem < 0 || closeRem < 0)
            return;

        if (index == s.size()) {
            if (openRem == 0 &&
                closeRem == 0 &&
                balance == 0) {

                res.insert(curr);
            }
            return;
        }

        char c = s[index];

        if (c != '(' && c != ')') {

            curr.push_back(c);

            solve(s, index + 1,
                  openRem, closeRem,
                  balance, curr, res);

            curr.pop_back();

            return;
        }

        // Remove current character
        if (c == '(' && openRem > 0) {

            solve(s, index + 1,
                  openRem - 1, closeRem,
                  balance, curr, res);
        }

        if (c == ')' && closeRem > 0) {

            solve(s, index + 1,
                  openRem, closeRem - 1,
                  balance, curr, res);
        }

        // Keep current character
        curr.push_back(c);

        if (c == '(') {

            solve(s, index + 1,
                  openRem, closeRem,
                  balance + 1,
                  curr, res);

        } else {

            if (balance > 0) {
                solve(s, index + 1,
                      openRem, closeRem,
                      balance - 1,
                      curr, res);
            }
        }

        curr.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {

        int openRem = 0;
        int closeRem = 0;

        for (char c : s) {

            if (c == '(') {
                openRem++;
            }
            else if (c == ')') {

                if (openRem > 0)
                    openRem--;
                else
                    closeRem++;
            }
        }

        set<string> res;
        string curr;

        solve(s, 0,
              openRem, closeRem,
              0, curr, res);

        return vector<string>(res.begin(), res.end());
    }
};