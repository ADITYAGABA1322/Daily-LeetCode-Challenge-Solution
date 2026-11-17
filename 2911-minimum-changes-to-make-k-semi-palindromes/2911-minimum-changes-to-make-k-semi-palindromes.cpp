class Solution {
    int segmentCost(const string& s, int l, int m,
                    const vector<vector<int>>& factors) {
        int best = m;
        for (int d : factors[m]) {
            int groups = m / d;  // Each group contains groups characters
            int changes = 0;
            for (int offset = 0; offset < d; offset++) {
                for (int t = 0; t < groups / 2;
                     t++) {  // Pair characters from opposite ends of the group
                    if (s[l + offset + t * d] !=
                        s[l + offset + (groups - 1 - t) * d]) {
                        changes++;
                    }
                }
            }
            best = min(best, changes);
        }
        return best;
    }

    int solve(int seg, int start, int n, const vector<vector<int>>& cost,
              vector<vector<int>>& memo) {
        if (seg == 1) {  // Only one segment remains
            return cost[start][n - 1];
        }
        if (memo[seg][start] != -1) {  // Already computed
            return memo[seg][start];
        }
        int best = n;
        int limit =
            n - 1 -
            2 * (seg -
                 1);  // Leave room for seg-1 segments after the first segment
        for (int e = start + 1; e <= limit; e++) {
            best = min(best,
                       cost[start][e] + solve(seg - 1, e + 1, n, cost, memo));
        }
        memo[seg][start] = best;
        return best;
    }

public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> factors(n + 1);
        // Precompute the proper divisors of each number
        for (int d = 1; d <= n / 2; d++) {
            for (int m = d * 2; m <= n; m += d) {
                factors[m].push_back(d);
            }
        }
        vector cost(n, vector<int>(n, 0));
        for (int l = 0; l + 1 < n; l++) {
            for (int r = l + 1; r < n;
                 r++) {  // Each substring must have length at least 2
                cost[l][r] = segmentCost(s, l, r - l + 1, factors);
            }
        }
        vector<vector<int>> memo(k + 1, vector<int>(n, -1));
        return solve(k, 0, n, cost, memo);
    }
};