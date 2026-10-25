class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    if(dfs(grid , i , j)) res++;
                }
            }
        }
        return res;
    }

    bool dfs(vector<vector<int>>& grid , int i , int j){
        if(i< 0 || i>= grid.size() || j<0 || j>=grid[0].size()) return false;
        if(grid[i][j] == 1) return true;
        grid[i][j] = 1;
        bool top = dfs(grid , i-1 , j);
        bool bottom = dfs(grid , i+1 , j);
        bool left = dfs(grid , i , j-1);
        bool right = dfs(grid , i , j+1);
        return top && bottom && left && right;
    }
    
};