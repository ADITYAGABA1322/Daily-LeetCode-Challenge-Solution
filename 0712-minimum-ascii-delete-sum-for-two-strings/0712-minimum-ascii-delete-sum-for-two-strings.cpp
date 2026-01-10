class Solution {
public:
    int m, n;
    int dp[1001][1001];

    int solve(string &s1, string &s2, int i, int j) {
        if (i >= m && j >= n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (i >= m)
            return dp[i][j] = s2[j] + solve(s1, s2, i, j + 1);

        if (j >= n)
            return dp[i][j] = s1[i] + solve(s1, s2, i + 1, j);

        if (s1[i] == s2[j])
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);

        int delete_s1 = s1[i] + solve(s1, s2, i + 1, j);
        int delete_s2 = s2[j] + solve(s1, s2, i, j + 1);

        return dp[i][j] = min(delete_s1, delete_s2);
    }

    int minimumDeleteSum(string s1, string s2) {
        m = s1.size();
        n = s2.size();
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};