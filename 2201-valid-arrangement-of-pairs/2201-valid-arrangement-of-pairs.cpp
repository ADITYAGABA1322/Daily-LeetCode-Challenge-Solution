class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adjacencyMatrix;
        unordered_map<int, int> inDegree, outDegree;

        // Build the adjacency list and track in-degrees and out-degrees
        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacencyMatrix[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        }

        vector<int> result;

        // Helper lambda function for DFS traversal,
        // you can make a seperate private function also
        function<void(int)> visit = [&](int node) {
            while (!adjacencyMatrix[node].empty()) {
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop_front();
                visit(nextNode);
            }
            result.push_back(node);
        };

        // Find the start node (outDegree == 1 + inDegree )
        int startNode = -1;
        for (const auto& entry : outDegree) {
            int node = entry.first;
            if (outDegree[node] == inDegree[node] + 1) {
                startNode = node;
                break;
            }
        }

        // If no such node exists, start from the first pair's first element
        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        // Start DFS traversal
        visit(startNode);

        // Reverse the result since DFS gives us the path in reverse
        reverse(result.begin(), result.end());

        // Construct the result pairs
        vector<vector<int>> pairedResult;
        for (int i = 1; i < result.size(); ++i) {
            pairedResult.push_back({result[i - 1], result[i]});
        }

        return pairedResult;
    }
};