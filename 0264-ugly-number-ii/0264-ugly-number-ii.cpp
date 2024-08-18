#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; } ();

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int t2 = 0 , t3 = 0 , t5 = 0;
        for(int i =1; i<n; i++){
            dp[i] = min({dp[t2] * 2 , dp[t3] * 3 , dp[t5] * 5});
            if(dp[i] == dp[t2] * 2) t2++;
            if(dp[i] == dp[t3] * 3) t3++;
            if(dp[i] ==  dp[t5] * 5) t5++;
           
        }
        return dp[n-1];
    }
};