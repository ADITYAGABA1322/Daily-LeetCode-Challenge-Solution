#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; } ();
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod = 1e9+7;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(m, vector<int>(n, 0)));
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(int move = 1; move <= maxMove; move++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    dp[move % 2][i][j] = 0;
                    for(auto& dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            dp[move % 2][i][j] = (dp[move % 2][i][j] + dp[(move-1) % 2][ni][nj]) % mod;
                        } else {
                            dp[move % 2][i][j] = (dp[move % 2][i][j] + 1) % mod;
                        }
                    }
                }
            }
        }
        return dp[maxMove % 2][startRow][startColumn];
    }
};

