class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Function to perform topological sort and return the order if possible
        auto topologicalSort = [&](const vector<vector<int>>& graph) {
            vector<int> indegree(k, 0);
            for (const auto& edges : graph) {
                for (int to : edges) {
                    indegree[to]++;
                }
            }
            queue<int> q;
            for (int i = 0; i < k; ++i) {
                if (indegree[i] == 0) q.push(i);
            }
            vector<int> order;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);
                for (int to : graph[node]) {
                    if (--indegree[to] == 0) q.push(to);
                }
            }
            return order.size() == k ? order : vector<int>();
        };

        // Initialize graphs
        vector<vector<int>> rowGraph(k), colGraph(k);
        for (const auto& cond : rowConditions) {
            rowGraph[cond[0] - 1].push_back(cond[1] - 1);
        }
        for (const auto& cond : colConditions) {
            colGraph[cond[0] - 1].push_back(cond[1] - 1);
        }

        // Perform topological sort
        vector<int> rowOrder = topologicalSort(rowGraph), colOrder = topologicalSort(colGraph);
        if (rowOrder.empty() || colOrder.empty()) return {}; // Cycle detected

        // Build the matrix
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        vector<int> rowPosition(k), colPosition(k);
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            matrix[rowPosition[i]][colPosition[i]] = i + 1;
        }

        return matrix;
    }
};