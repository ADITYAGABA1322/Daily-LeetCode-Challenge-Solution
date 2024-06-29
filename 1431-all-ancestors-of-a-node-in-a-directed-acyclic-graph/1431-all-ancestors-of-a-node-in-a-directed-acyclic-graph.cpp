class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Initialize adjacency list for each node and ancestors list
        vector<vector<int>> adjacencyList(n);
        vector<vector<int>> ancestors(n);

        // Populate the adjacency list with edges
        for (vector<int> edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
        }

        // Perform DFS for each node to find all its ancestors
        for (int i = 0; i < n; i++) {
            findAncestorsDFS(i, adjacencyList, i, ancestors);
        }

        return ancestors;
    }

private:
    // Helper method to perform DFS and find ancestors
    void findAncestorsDFS(int ancestor, vector<vector<int>>& adjacencyList,
                          int currentNode, vector<vector<int>>& ancestors) {
        for (int childNode : adjacencyList[currentNode]) {
            // Check if the ancestor is already added to avoid duplicates
            if (ancestors[childNode].empty() ||
                ancestors[childNode].back() != ancestor) {
                ancestors[childNode].push_back(ancestor);
                findAncestorsDFS(ancestor, adjacencyList, childNode, ancestors);
            }
        }
    }
};