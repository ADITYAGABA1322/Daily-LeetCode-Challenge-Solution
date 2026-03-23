// Top down Dp
// class Solution {
// public:
//     typedef long long ll;
//     int m , n;
//     int mod = 1e9+7;
//     vector<vector<pair<ll , ll>>> dp;
//     int maxProductPath(vector<vector<int>>& grid) {
//         m = grid.size() , n = grid[0].size();
//         dp = vector<vector<pair<ll , ll>>>(m , vector<pair<ll , ll>>(n , {LLONG_MIN , LLONG_MAX}));
//         auto[maxPro , minPro] = solve(0 , 0 , grid);
//         return maxPro < 0 ? -1 : maxPro % mod;
//     }

//     pair<ll , ll> solve(int i , int j ,  vector<vector<int>>& grid){
//         if(i == m-1 && j == n-1){
//             return {grid[i][j] , grid[i][j]};
//         }
//         if(dp[i][j] != make_pair(LLONG_MIN , LLONG_MAX)) return dp[i][j];
//         ll maxVal = LLONG_MIN;
//         ll minVal = LLONG_MAX;

//         if(i+1 < m){
//             auto [downMax , downMin] = solve(i+1 , j , grid);
//             maxVal = max({maxVal , grid[i][j] * downMax , grid[i][j] * downMin});
//             minVal = min({minVal , grid[i][j] * downMax , grid[i][j] * downMin});
//         }

//         if(j+1<n){
//             auto[rightMax , rightMin] = solve(i , j+1 , grid);
//             maxVal = max({maxVal , grid[i][j] * rightMax , grid[i][j] * rightMin});
//             minVal = min({minVal , grid[i][j] * rightMax , grid[i][j] * rightMin});
//         }

//         return dp[i][j] = {maxVal , minVal};
//     }
// };

// Bottom up dp
class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<pair<ll , ll >>> dp(m , vector<pair<ll , ll>>(n));

        // base case
        dp[0][0] = {grid[0][0] , grid[0][0]};
        
        // filling first row
        for(int j=1; j<n; j++){
            dp[0][j].first = dp[0][j-1].first * grid[0][j]; // max val
            dp[0][j].second = dp[0][j-1].second * grid[0][j]; // min val
        }

        // filling first col
        for(int i=1; i<m; i++){
            dp[i][0].first = dp[i-1][0].first * grid[i][0]; // max val 
            dp[i][0].second = dp[i-1][0].second * grid[i][0]; // min val
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                ll upMax = dp[i-1][j].first;
                ll upMin = dp[i-1][j].second;

                ll leftMax = dp[i][j-1].first;
                ll leftMin = dp[i][j-1].second;

                dp[i][j].first = max({upMax* grid[i][j] , upMin * grid[i][j] , leftMax * grid[i][j] , leftMin * grid[i][j]});
                dp[i][j].second = min({upMax* grid[i][j] , upMin * grid[i][j] , leftMax * grid[i][j] , leftMin * grid[i][j]});
            }
        }
        auto [maxPro , minPro] = dp[m-1][n-1];
        return maxPro < 0  ? -1 : maxPro % mod;
    }
};