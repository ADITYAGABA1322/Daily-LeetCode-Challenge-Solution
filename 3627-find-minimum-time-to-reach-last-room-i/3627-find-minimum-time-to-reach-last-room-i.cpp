class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // dunegon m*n matrix ok  given 2d arr moveTime of size n*m moveTime ok the problme is so much good and design but description is poor by give n*m it triggers me to use graph and same question relate me  with course schedule 3 not 2 or 1 becuase 3 use shortest path or heap easily we solve it but in that we use graph using shortest path concept either using dijkstra or floyd warshall still i go with dijkstra beacuse we use dist as time in this to move from one grid to another by checking same adjacent wall means grid[0][i] is equal grid[i][0] means in both i. is same ok for that we declare the priority queue of min heap using the dist and minTime to cnt using queue and iterate getting curr and check in if we go to end or not by check same adjacent but they are already sharing we use dirs concept here we are done to cnt it 
// Analyzing Your Dungeon Navigation Approach
// Your approach has some good insights but also some misunderstandings about the problem. Let me clarify:

// Understanding Your Approach
// You're thinking about using:

// Graph algorithms (Dijkstra's algorithm specifically)
// Shortest path finding concepts
// A priority queue for minimum time tracking
// These are excellent tools for this problem type, but let's clarify some details.

// Problem Clarification
// The problem states:

// You start at room (0,0) at time t=0
// You can move to adjacent rooms, taking 1 second per move
// Important: You can only enter a room when the current time ≥ moveTime[i][j]
// The goal is to find minimum time to reach room (n-1, m-1)
        int n = moveTime.size() , m = moveTime[0].size();
        vector<vector<int>> vis(n , vector<int>(m , INT_MAX));
        vis[0][0] = 0;
        vector<pair<int,int>> dirs = {{-1,0} , {0 , 1} , {1 , 0} , {0 , -1}};
        priority_queue<vector<int> , vector<vector<int>> , greater<>>pq;
        pq.push({0 , 0 , 0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int time = curr[0];
            int row = curr[1];
            int col = curr[2];
             if(time > vis[row][col]) continue;
            if(row == n-1 && col == m-1) return time;
           
            for(auto& dir : dirs){
                int newRow = row + dir.first , newCol = col + dir.second;
                if(newRow>=0 && newRow <n && newCol>=0 && newCol<m){
                    int newTime = max(time , moveTime[newRow][newCol]) + 1;
                    if(newTime < vis[newRow][newCol]){
                        vis[newRow][newCol] = newTime;
                        pq.push({newTime , newRow , newCol});
                    }
                }
            }
        }
        return -1;
    }
};