class Solution {
public:
    typedef long long ll;
    int n;

    vector<vector<vector<ll>>> dp;

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<ll>> colPref(n + 1, vector<ll>(n, 0));

        for (int col = 0; col < n; col++) {
            for (int row = 1; row <= n; row++) {
                colPref[row][col] = colPref[row - 1][col] + grid[row - 1][col];
            }
        }

        dp.assign(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, -1)));

        return solve(false, 0, 0, grid, colPref);
    }

    ll solve(bool prevTaken, int prevH, int col,
             vector<vector<int>>& grid,
             vector<vector<ll>>& colPref) {

        if (col == n) return 0;

        ll &memo = dp[col][prevH][prevTaken];
        if (memo != -1) return memo;

        ll res = 0;

        for (int height = 0; height <= n; height++) {
            ll prevColS = 0;
            ll currColS = 0;

            if (!prevTaken && col - 1 >= 0 && height > prevH) {
                prevColS += colPref[height][col - 1] - colPref[prevH][col - 1];
            }

            if (prevH > height) {
                currColS += colPref[prevH][col] - colPref[height][col];
            }

            ll currScoreTaken =
                currColS + prevColS + solve(true, height, col + 1, grid, colPref);

            ll currScoreNotTaken =
                prevColS + solve(false, height, col + 1, grid, colPref);

            res = max({res, currScoreTaken, currScoreNotTaken});
        }

        return memo = res;
    }
};