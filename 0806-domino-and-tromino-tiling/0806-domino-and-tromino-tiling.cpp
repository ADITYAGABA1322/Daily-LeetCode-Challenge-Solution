class Solution {
public:
    int numTilings(int n) {
        // given an int n and reuturn ways to tile an 2 * n  their is scnerio for 2*n+1 and 2*n+2 we derive the formula for this one an realtion with that sooray the pattern is look like for n = 1 is 1 ok and for 2 is 2 but from 3 the game is change like for 3 comes 5 but how u know 5 comes fomr 2*2 + 1 and for n = 4 11 comes form 5*2+1 ok 
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        vector<long long> dp(n+1);
        int mod = 1e9+7;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4; i<=n; i++){
            dp[i] = (dp[i-1] * 2 + dp[i-3]) % mod;
        }
        return dp[n];
    }
};