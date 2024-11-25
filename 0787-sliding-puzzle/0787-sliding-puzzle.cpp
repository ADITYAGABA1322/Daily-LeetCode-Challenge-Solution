
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";
        for (const auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }

        vector<vector<int>> neighbors = {
            {1, 3}, {0, 2, 4}, {1, 5},
            {0, 4}, {1, 3, 5}, {2, 4}
        };

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [current, moves] = q.front();
            q.pop();

            if (current == target) {
                return moves;
            }

            int zeroPos = current.find('0');
            for (int neighbor : neighbors[zeroPos]) {
                string next = current;
                swap(next[zeroPos], next[neighbor]);
                if (visited.find(next) == visited.end()) {
                    q.push({next, moves + 1});
                    visited.insert(next);
                }
            }
        }

        return -1; // If the puzzle is unsolvable
    }
};