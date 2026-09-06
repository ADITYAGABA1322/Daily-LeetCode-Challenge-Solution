class Solution {
public:
    int dp[1001][10001];
    int numDistinct(string s, string t) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , s , t);
    }
    int solve(int i, int j , string& s , string& t){
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0, skip = 0;
        if(s[i] == t[j]) {
            take = solve(i+1 , j+1 , s , t);
            skip = solve(i+1 , j , s , t);
            return  dp[i][j] = take+skip;
        } else {
            return dp[i][j] = solve(i+1 , j , s , t);
        }
    }
};