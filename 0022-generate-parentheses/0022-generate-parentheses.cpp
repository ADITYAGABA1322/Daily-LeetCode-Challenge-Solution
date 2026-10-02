class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        solve(res , s , 0 , 0, n);
        return res;
    }

    void solve(vector<string>& res, string s , int open , int close , int n){
        if(s.size() == 2*n){
            res.push_back(s);
            return;
        }
        if(open<n) solve(res , s + '(' , open + 1 , close , n);
        if(close<open) solve(res , s + ')' , open , close + 1 , n);

    }
};