class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        constexpr int MOD = 1'000'000'007;

        int m = grid.size();
        int n = grid[0].size();

        // f[i][j][0]: enter (i, j) by moving down
        // f[i][j][1]: enter (i, j) by moving right
        vector<vector<array<long long, 2>>> f(
            m, vector<array<long long, 2>>(n, {0, 0}));

        f[0][0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    if (grid[i - 1][j] == 0) {
                        f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1]) % MOD;
                    } else {
                        f[i][j][0] = f[i - 1][j][1];
                    }
                }

                if (j > 0) {
                    if (grid[i][j - 1] == 0) {
                        f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1]) % MOD;
                    } else {
                        f[i][j][1] = f[i][j - 1][0];
                    }
                }
            }
        }

        return (f[m - 1][n - 1][0] + f[m - 1][n - 1][1]) % MOD;
    }
};