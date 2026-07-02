class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.emplace(grid[0][0], 0, 0);
        while (!pq.empty()) {
            auto [val, cx, cy] = pq.top();
            pq.pop();
            if (dis[cx][cy] >= 0) {
                continue;
            }
            dis[cx][cy] = val;
            for (int k = 0; k < 4; k++) {
                int nx = cx + dirs[k][0];
                int ny = cy + dirs[k][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                    dis[nx][ny] >= 0) {
                    continue;
                }
                pq.emplace(val + grid[nx][ny], nx, ny);
            }
        }

        return dis[m - 1][n - 1] < health;
    }
};