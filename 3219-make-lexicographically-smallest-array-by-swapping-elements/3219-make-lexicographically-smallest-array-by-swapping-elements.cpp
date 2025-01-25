#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        UnionFind uf(n);

        // Sort the array while keeping track of the original indices
        vector<pair<int, int>> sortedNums;
        for (int i = 0; i < n; ++i) {
            sortedNums.push_back({nums[i], i});
        }
        sort(sortedNums.begin(), sortedNums.end());

        // Create groups using union-find
        for (int i = 0; i < n - 1; ++i) {
            if (abs(sortedNums[i].first - sortedNums[i + 1].first) <= limit) {
                uf.unite(sortedNums[i].second, sortedNums[i + 1].second);
            }
        }

        // Collect elements in each group
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            groups[root].push_back(nums[i]);
        }

        // Sort elements in each group
        for (auto& [root, group] : groups) {
            sort(group.begin(), group.end());
        }

        // Reconstruct the array
        vector<int> result(n);
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            result[i] = groups[root][index[root]++];
        }

        return result;
    }
};

