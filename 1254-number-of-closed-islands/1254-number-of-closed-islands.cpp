class Solution {
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (sz[x] < sz[y])
            swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;
        int OUTSIDE = total;

        parent.resize(total + 1);
        sz.assign(total + 1, 1);

        for (int i = 0; i <= total; i++)
            parent[i] = i;

        vector<int> dx = {1, 0};
        vector<int> dy = {0, 1};

        // Step 1: Union connected land cells.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    continue;

                int id = i * n + j;

                // Step 2: Connect boundary land to OUTSIDE.
                if (i == 0 || i == m - 1 ||
                    j == 0 || j == n - 1) {
                    unite(id, OUTSIDE);
                }

                // Step 3: Union with right and bottom neighbors.
                for (int k = 0; k < 2; k++) {
                    int r = i + dx[k];
                    int c = j + dy[k];

                    if (r < m && c < n &&
                        grid[r][c] == 0) {
                        int neighbor = r * n + c;
                        unite(id, neighbor);
                    }
                }
            }
        }

        // Step 4: Count distinct land components
        // that are NOT connected to OUTSIDE.
        int outsideRoot = find(OUTSIDE);
        unordered_set<int> components;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    continue;

                int id = i * n + j;
                int root = find(id);

                if (root != outsideRoot)
                    components.insert(root);
            }
        }

        return components.size();
    }
};