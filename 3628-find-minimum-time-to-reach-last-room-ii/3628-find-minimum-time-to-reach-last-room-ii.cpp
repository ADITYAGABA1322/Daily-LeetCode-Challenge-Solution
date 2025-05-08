class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        
        // Directions for adjacent rooms
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // We need a 3D visited array to track [row][col][moveType]
        // moveType: 0 = next move takes 1 second, 1 = next move takes 2 seconds
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        vis[0][0][0] = 0;  // Start at (0,0) with move type 0 (next move takes 1 second)
        
        // Priority queue for {time, row, col, moveType}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0, 0});  // {time, row, col, moveType}
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int time = curr[0];
            int row = curr[1];
            int col = curr[2];
            int moveType = curr[3];  // 0 = next move takes 1 second, 1 = next move takes 2 seconds
            
            // If we found a better path already, skip
            if (time > vis[row][col][moveType]) continue;
            
            // If we reached the destination
            if (row == n-1 && col == m-1) {
                return time;
            }
            
            // Try all adjacent rooms
            for (auto& dir : dirs) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                
                // Check if valid room
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    // Get move duration based on current moveType
                    int moveDuration = (moveType == 0) ? 1 : 2;
                    
                    // Calculate new time
                    int newTime = max(time, moveTime[newRow][newCol]) + moveDuration;
                    
                    // Next moveType is the opposite of current
                    int nextMoveType = 1 - moveType;
                    
                    // Update if we found a better path
                    if (newTime < vis[newRow][newCol][nextMoveType]) {
                        vis[newRow][newCol][nextMoveType] = newTime;
                        pq.push({newTime, newRow, newCol, nextMoveType});
                    }
                }
            }
        }
        
        return -1;  // Should not reach here if problem is valid
    }
};