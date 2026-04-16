class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        for (int q : queries) {
            int v = nums[q];
            vector<int>& indices = mp[v];
            int sz = indices.size();

            if (sz == 1) {
                result.push_back(-1);
                continue;
            }

            // Binary search to find q's OWN position in indices
            int left = 0, right = sz - 1, pos = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (indices[mid] < q) {      // strict < so pos lands ON q
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            pos = left; // now indices[pos] == q exactly

            // Neighbors AROUND q (not q itself)
            int c1 = indices[(pos + 1) % sz];           // right neighbor
            int c2 = indices[(pos - 1 + sz) % sz];      // left neighbor

            auto circDist = [&](int i, int j) {
                int diff = abs(i - j);
                return min(diff, n - diff);
            };

            int d1 = circDist(q, c1);
            int d2 = circDist(q, c2);

            result.push_back(min(d1, d2));
        }

        return result;
    }
};