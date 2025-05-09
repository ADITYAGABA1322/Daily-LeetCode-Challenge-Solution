class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        vector<int> psum(11);
        vector<vector<long long>> comb(maxOdd + 1,
                                       vector<long long>(maxOdd + 1));
        long long memo[10][target + 1][maxOdd + 1];
        memset(memo, 0xff, sizeof(memo));
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }
        for (int i = 9; i >= 0; i--) {
            psum[i] = psum[i + 1] + cnt[i];
        }

        function<long long(int, int, int)> dfs = [&](int pos, int curr,
                                                     int oddCnt) -> long long {
            /* If the remaining positions cannot be legally filled, or if the
             * sum of the elements at the current odd positions is greater than
             * the target value */
            if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
                return 0;
            }
            if (pos > 9) {
                return curr == target && oddCnt == 0;
            }
            if (memo[pos][curr][oddCnt] != -1) {
                return memo[pos][curr][oddCnt];
            }
            /* Even-numbered positions remaining to be filled */
            int evenCnt = psum[pos] - oddCnt;
            long long res = 0;
            for (int i = max(0, cnt[pos] - evenCnt); i <= min(cnt[pos], oddCnt);
                 i++) {
                /* The current digit is filled with i positions at odd
                 * positions, and cnt[pos] - i positions at even positions */
                long long ways =
                    comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i] % MOD;
                res = (res +
                       ways * dfs(pos + 1, curr + i * pos, oddCnt - i) % MOD) %
                      MOD;
            }
            memo[pos][curr][oddCnt] = res;
            return res;
        };

        return dfs(0, 0, maxOdd);
    }
};