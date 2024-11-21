class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m , vector<char>(n , 'U'));
        for(auto guard : guards) grid[guard[0]][guard[1]] = 'G';
        for(auto wall : walls) grid[wall[0]][wall[1]] = 'W';
        vector<pair<int , int>> dirs = {{-1,0} , {0,-1} , {1, 0} , {0,1}};
        auto bfs = [&](int x , int y){
            queue<pair<int , int >> q;
            for(auto dir : dirs){
                int nx = x + dir.first , ny = y + dir.second;
                while(nx >= 0 && nx < m && ny>=0 && ny < n && grid[nx][ny] != 'G' && grid[nx][ny] != 'W'){
                    grid[nx][ny] = 'V';
                    nx += dir.first;
                    ny += dir.second;
                }
            }
        };
        for(auto guard : guards) bfs(guard[0] , guard[1]);
        int unCnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 'U') unCnt++;
            }
        }
        return unCnt;
    }
};