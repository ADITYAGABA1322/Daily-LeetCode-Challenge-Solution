class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameters of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Calculate the longest path that spans across both trees
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        // Return the maximum of the three possibilities
        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }

    // Function to find the diameter of a tree using two BFS calls
    int findDiameter(int n, vector<vector<int>>& adjList) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        auto [farthestNode, _] = findFarthestNode(n, adjList, 0);

        // Second BFS from the farthest node to determine the diameter
        auto [_, diameter] = findFarthestNode(n, adjList, farthestNode);
        return diameter;
    }

    // BFS helper function to find the farthest node and its distance from the
    // source
    pair<int, int> findFarthestNode(int n, vector<vector<int>>& adjList,
                                    int sourceNode) {
        queue<int> nodesQueue;
        vector<bool> visited(n, false);
        // Push source node into the queue
        nodesQueue.push(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0, farthestNode = sourceNode;

        // Explore neighbors
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                // Update farthest node
                // The farthest node is the last one that was popped out of the
                // queue.
                farthestNode = currentNode;

                for (int neighbor : adjList[currentNode]) {
                    // Explore neighbors
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nodesQueue.push(neighbor);
                    }
                }
            }
            if (!nodesQueue.empty()) maximumDistance++;
        }
        return {farthestNode, maximumDistance};
    }
};