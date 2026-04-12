class Solution {
public:
    int getDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        int dp[n][26][26];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                fill(dp[i][j], dp[i][j] + 26, INT_MAX >> 1);
            }
        }
        for (int i = 0; i < 26; ++i) {
            dp[0][i][word[0] - 'A'] = dp[0][word[0] - 'A'][i] = 0;
        }

        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = getDistance(prev, cur);
            for (int j = 0; j < 26; ++j) {
                dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][prev][j] + d);
                dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][prev] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = getDistance(k, cur);
                        dp[i][cur][j] =
                            min(dp[i][cur][j], dp[i - 1][k][j] + d0);
                        dp[i][j][cur] =
                            min(dp[i][j][cur], dp[i - 1][j][k] + d0);
                    }
                }
            }
        }

        int ans = INT_MAX >> 1;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = min(ans, dp[n - 1][i][j]);
            }
        }
        return ans;
    }
};