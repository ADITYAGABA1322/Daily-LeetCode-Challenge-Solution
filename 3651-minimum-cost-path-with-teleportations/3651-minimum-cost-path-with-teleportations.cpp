class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        // Recursion + TLE  -> O(N^2M^2K)
        //     int m = grid.size() , n = grid[0].size();
        //     vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1 ,
        //     vector<int>(k+1 , -1))); return solve(0 , 0 , dp , grid , k );
        // }
        // int solve(int i , int j , vector<vector<vector<int>>>& dp ,
        // vector<vector<int>>& grid , int k){
        //     int m = grid.size() , n = grid[0].size();
        //     if(i == m || j == n || k<0) return 1e9;
        //     if(i == m-1 && j == n-1) return 0;
        //     if(dp[i][j][k] != -1) return dp[i][j][k];
        //     int path1 = 1e9 , path2 = 1e9 , mini = 1e9;
        //     if(i+1 < m) path1 = grid[i+1][j] + solve(i+1 , j , dp , grid ,
        //     k); if(j+1 < n) path2 = grid[i][j+1] + solve(i , j+1 , dp ,grid ,
        //     k); for(int r=0 ; r<m; r++){
        //         for(int c=0; c<n; c++){
        //             if((r == i && c == j) || grid[r][c] > grid[i][j])
        //             continue; mini = min(mini , solve(r , c , dp , grid ,
        //             k-1));
        //         }
        //     }
        //     return dp[i][j][k] = min(mini , min(path1 , path2));

        // Lets make teleportation O(1) and not nened of k also to sotre in dp
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, 1e9));
        vector<pair<int, int>> cells;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cells.push_back({i , j});
            }
        }
        sort(cells.begin() , cells.end() , [&](auto a , auto b){
            return grid[a.first][a.second] < grid[b.first][b.second];
        });

        for(int step = 0; step<=k; step++){
            int best = 1e9;
            for(int idx = 0; idx < cells.size(); idx++){
                int r = cells[idx].first;
                int c = cells[idx].second;
                best = min(best , cost[r][c]);
                if(idx+1 < cells.size() && grid[r][c] == grid[cells[idx+1].first][cells[idx+1].second]) continue;
                int prev = idx;
                while(prev>=0 && grid[cells[prev].first][cells[prev].second] == grid[r][c]){
                    cost[cells[prev].first][cells[prev].second] = best;
                    prev--;
                }
            }
            for(int i=m-1; i>=0; i--){
                for(int j=n-1; j>=0; j--){
                    if(i == m-1 && j == n-1){
                        cost[i][j] = 0;
                        continue;
                    }
                    if(i+1 < m){
                        cost[i][j] = min(cost[i][j], cost[i+1][j] + grid[i+1][j]);
                    }
                    if(j+1 <n){
                        cost[i][j] = min(cost[i][j], cost[i][j+1] + grid[i][j+1]);
                    }
                }
            }
        }
        return cost[0][0];
    }
};