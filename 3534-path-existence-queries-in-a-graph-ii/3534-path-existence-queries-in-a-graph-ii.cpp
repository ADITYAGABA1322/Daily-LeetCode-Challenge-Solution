class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<int> idx(n), pos(n), res;
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(),
             [&](int a, int b) { return nums[a] < nums[b]; });
        for (int i = 0; i < n; i++) {
            pos[idx[i]] = i;
        }

        int m = 32 - __builtin_clz(n);
        vector<vector<int>> f(n, vector<int>(m));

        for (int i = 0, left = 0; i < n; i++) {
            while (nums[idx[i]] - nums[idx[left]] > maxDiff) left++;
            f[i][0] = left;
        }

        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
        }

        for (auto& q : queries) {
            auto [x, y] = pair(pos[q[0]], pos[q[1]]);
            if (x > y) {
                swap(x, y);
            }
            if (x == y) {
                res.push_back(0);
                continue;
            }

            int step = 0;
            for (int i = m - 1; i >= 0; i--) {
                if (f[y][i] > x) {
                    y = f[y][i];
                    step += 1 << i;
                }
            }

            res.push_back(f[y][0] <= x ? step + 1 : -1);
        }
        return res;
    }
};