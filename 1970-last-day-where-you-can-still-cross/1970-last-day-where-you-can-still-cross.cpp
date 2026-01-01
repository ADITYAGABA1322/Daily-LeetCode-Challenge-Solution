class Solution {
public:
    vector<vector<int>> directions{{1 ,0} , {-1 , 0} , {0 , 1} , { 0 , -1}};
    bool canCross(int row, int col, vector<vector<int>>& cells , int day){
        vector<vector<int>> grid(row , vector<int>(col , 0));
        queue<pair<int , int>> q;
         for(int i = 0; i < day; i++){
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }
        for(int i=0; i<col; i++){
            if(grid[0][i] == 0) {
                q.push({0 , i});
                grid[0][i] = -1;
            }
        }
        while(!q.empty()){
            auto[r , c] = q.front();
            q.pop();
            if(r == row-1) return true;
            for(auto dir : directions){
                int newR = r + dir[0] , newC = c  + dir[1];
                if(newR >= 0 && newR < row && newC >= 0 && newC < col && grid[newR][newC] == 0){
                    grid[newR][newC] = -1;
                    q.push({newR , newC});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0 , r = cells.size() , lastDay = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(canCross(row , col  , cells , mid)){
                lastDay = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return lastDay;
    }
};