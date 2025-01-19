class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // stil similar problem related to Trapping Rain Water but in that case we sue two pointer or dp i think but the game is change we give matrix heightmap ok each unit cell ok 2d elevation map return vol of water it can trap after raining ok if form huma mind what i think first we build height first according to the array means block fomr the top we see whree water wll fill when rains ok and see fromt he top but in the code what we check we left right ok the building or  top bottom ok we the heights map like a graph or we say using queue or priority queue ok why using grpah here we want check the matrix bloack like we traverse the heght map ofarrt and accrding to that means we declare n and m and then declare queue and perfrom bfs how we go level by level and check is the space form checking the block should it cover or not and then we perfrom bfs but how it sill stcuk 
        if(heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size() , n = heightMap[0].size();
        vector<vector<bool>> vis(m , vector<bool>(n , false));
          priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0; i<m; i++){
            pq.push({heightMap[i][0] , {i , 0}});
            pq.push({heightMap[i][n-1] , {i , n-1}});
            vis[i][0] = true;
            vis[i][n-1] = true;
        }
        for(int j=1; j<n-1; j++){
            pq.push({heightMap[0][j] , {0 , j}});
            pq.push({heightMap[m-1][j] , {m-1 , j}});
            vis[0][j] = true;
            vis[m-1][j] = true;
        }
        vector<pair<int , int>> dir = {{0,1} , {-1,0} , {0,-1} , {1 , 0}};
        int cnt = 0;
        while(!pq.empty()){
            auto [height , cell] = pq.top();
            pq.pop();
            int x = cell.first;
            int y = cell.second;
            for(auto [dx , dy] : dir){
                int nx = x + dx;
                int ny = y + dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                    cnt += max(0 , height - heightMap[nx][ny]);
                    pq.push({max(height , heightMap[nx][ny]) , {nx , ny}});
                    vis[nx][ny] = true;
                }
            }
        }
        return cnt;
    }
};