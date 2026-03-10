class Solution {
public:
    // int M = 1e9+7;
    // int dp[201][201][2];
    // int numberOfStableArrays(int zero, int one, int limit) {
    //     memset(dp , -1 , sizeof(dp));
    //     int startWith1 =  solve(zero , one , true , limit);
    //     int startWith0 = solve(zero, one , false , limit);
    //     return (startWith1  + startWith0) % M;
    // }

    // int solve(int zeroLeft, int oneLeft , bool lastOne , int limit){
    //     if(zeroLeft == 0 && oneLeft == 0) return 1;
    //     if(dp[zeroLeft][oneLeft][lastOne] != -1) return dp[zeroLeft][oneLeft][lastOne];
    //     int res = 0;
    //     if(lastOne == true){
    //         for(int i=1; i<=min(zeroLeft , limit); i++){
    //             res =(res + solve(zeroLeft - i , oneLeft , false , limit))  % M;
    //         }
    //     } else {
    //         for(int i=1; i<=min(oneLeft ,  limit); i++){
    //             res = (res + solve(zeroLeft , oneLeft - i , true , limit)) % M;
    //         }
    //     }
    //     return dp[zeroLeft][oneLeft][lastOne] = res;
    // }

    // bottom up approach for 1000 constraint too 

    int numberOfStableArrays(int zero, int one, int limit){
        vector<vector<vector<long long >>> dp(zero + 1 ,vector<vector<long long>>(one +1 , vector<long long> (2)));
        long long mod = 1e9+7;
        for(int i=0; i<=min(zero , limit); i++) dp[i][0][0] = 1;
        for(int j=0; j<=min(one , limit); j++) dp[0][j][1] = 1;
        for(int i=1; i<=zero; i++){
            for(int j=1; j<=one; j++){
                if(i>limit) dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] - dp[i-limit-1][j][1];
                else dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;

                if(j>limit) dp[i][j][1] = dp[i][j-1][1] + dp[i][j-1][0] - dp[i][j-limit-1][0];
                else dp[i][j][1] = dp[i][j-1][1] + dp[i][j-1][0] ;
                dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};