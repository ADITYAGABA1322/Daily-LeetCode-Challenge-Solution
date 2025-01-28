class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        // we have a problme to solve that we given gird ok og m*n and a land grid[r][c] = 0  and water cell contain fish grid[r][c] > 0 ok sipmple and fisher catch fish and foll op Catch all the fish at cell (r, c), or Move to any adjacent water cell. ok reurn max no og fish catch ok.  we given mat or we say grid we foolow the op and check first we leave the 0 thing means land ok and we capture above ting and catch the in row and col and move to any adj cel means i to i+1 or j to j+1 or i to j+1 or j to i+1 means in all four dirc cause ad ok using graph best feeling to solve this problem but how we need to check only > 0 and using the bdf and trverse in all 4 dir like i am given to you for find adj and cnt the no of he catch and want to mxize we use the max in row and col acc to that check adj pos and reutn the cnt ok 
        int m = grid.size() , n = grid[0].size();
        vector<vector<bool>> vis(m , vector<bool>(n , false));
        int maxFish = 0;
        vector<pair<int , int>> dir = {{-1 , 0} , {0 , 1} , {1 ,0} , {0 , -1}};
        function<int(int , int)>dfs = [&](int x , int y){
            vis[x][y] = true;
            int fishCnt = grid[x][y];
            for(auto [dx , dy] : dir){
                int nx = x+dx;
                int ny =  y+dy;
                if(nx>=0 && nx <m && ny>=0 && ny < n && grid[nx][ny] > 0 && !vis[nx][ny]){
                    fishCnt += dfs(nx , ny);
                }
            }
            return fishCnt;
        };

        for(int i=0 ;i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    int fishCnt = dfs(i , j);
                    maxFish = max(maxFish , fishCnt);
                }
            }
            
        }
        return maxFish;
    }
};