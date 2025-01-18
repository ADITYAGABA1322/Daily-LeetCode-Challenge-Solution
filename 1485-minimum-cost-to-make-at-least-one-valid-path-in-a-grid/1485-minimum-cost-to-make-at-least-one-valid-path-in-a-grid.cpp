#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        
        // Directions: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Start from the top-left cell
        dq.push_front({0, 0});
        cost[0][0] = 0;
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            // Explore all possible directions
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i].first;
                int ny = y + directions[i].second;
                int newCost = cost[x][y] + (grid[x][y] != i + 1);
                
                // Check if the new position is within bounds and if we found a cheaper way to reach it
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    if (grid[x][y] == i + 1) {
                        dq.push_front({nx, ny});
                    } else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
        
        return cost[m-1][n-1];
    }
};
