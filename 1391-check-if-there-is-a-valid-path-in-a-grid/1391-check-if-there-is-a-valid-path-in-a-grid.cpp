class Solution {
public:
    int m , n;
    unordered_map<int , vector<vector<int>>> dirs = {
            {1 , {{0 , -1} , {0 , 1}}},
            {2 , {{-1 , 0} , {1 , 0}}},
            {3 , {{0 , -1} , {1 , 0}}},
            {4 , {{0 , 1} , {1 , 0}}},
            {5 , {{0 , -1} , {-1 , 0}}},
            {6 , {{-1 , 0} , {0 , 1}}}
    };
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size() , n = grid[0].size();
        vector<vector<bool>> vis(m , vector<bool>(n , false));
        return dfs(grid , 0 , 0 , vis);
    }

    bool dfs(vector<vector<int>>& grid, int i , int j , vector<vector<bool>>& vis){
        if(i == m-1 && j == n-1) return true;
        vis[i][j] = true;
        for(auto dir: dirs[grid[i][j]]){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || vis[new_i][new_j] ) continue;
            for(auto backDir: dirs[grid[new_i][new_j]]){
                if(new_i + backDir[0] == i && new_j + backDir[1] == j){
                    if(dfs(grid , new_i , new_j, vis)) return true;
                }
            }
        }
        return false;
    }
};