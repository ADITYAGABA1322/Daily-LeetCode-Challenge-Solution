class Solution {
    // Directions in which we can traverse inside the grids.
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    bool isCellLand(int x, int y, vector<vector<int>>& grid) {
        return grid[x][y] == 1;
    }

    // Union-Find class.
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> rank;

        // Itialize union-find object with 'n' elements.
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        // Find the root of element 'u', using the path-compression technique.
        int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        // Union two components of elements 'u' and 'v' respectively on the
        // basis of their ranks.
        void unionSets(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU != rootV) {
                if (rank[rootU] > rank[rootV]) {
                    parent[rootV] = rootU;
                } else if (rank[rootU] < rank[rootV]) {
                    parent[rootU] = rootV;
                } else {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        }
    };

    // Helper method to convert (x, y) position to 1-dimensional index.
    int convertToIndex(int x, int y, int totalCols) {
        return x * totalCols + y;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();
        UnionFind uf(totalRows * totalCols);

        // Traverse on each land cell of 'grid2'.
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (isCellLand(x, y, grid2)) {
                    // Union adjacent land cells with the current land cell.
                    for (auto& direction : directions) {
                        int nextX = x + direction[0], nextY = y + direction[1];
                        if (nextX >= 0 && nextY >= 0 && nextX < totalRows &&
                            nextY < totalCols &&
                            isCellLand(nextX, nextY, grid2)) {
                            uf.unionSets(
                                convertToIndex(x, y, totalCols),
                                convertToIndex(nextX, nextY, totalCols));
                        }
                    }
                }
            }
        }

        // Traverse on 'grid2' land cells and mark that cell's root not a
        // sub-island if land cell not present at the respective position in
        // 'grid1'.
        vector<bool> isSubIsland(totalRows * totalCols, true);
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (isCellLand(x, y, grid2) && !isCellLand(x, y, grid1)) {
                    int root = uf.find(convertToIndex(x, y, totalCols));
                    isSubIsland[root] = false;
                }
            }
        }

        // Count all the sub-islands.
        int subIslandCounts = 0;
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (isCellLand(x, y, grid2)) {
                    int root = uf.find(convertToIndex(x, y, totalCols));
                    if (isSubIsland[root]) {
                        subIslandCounts++;
                        // One cell can be the root of multiple land cells, so
                        // to avoid counting the same island multiple times and
                        // mark it as false.
                        isSubIsland[root] = false;
                    }
                }
            }
        }

        return subIslandCounts;
    }
};