#include <numeric>
class Solution {
public:
    int n;
    int mod = 1e9+7;
    int dp[200][201][201];
    int solve(int i , int g1 , int g2 , vector<int>& nums){
        if(i == n){
            if(g1 == 0 && g2 == 0) return 0;
            else if(g1 == g2) return 1;
            else return 0;
        }
        if(dp[i][g1][g2] != -1) return dp[i][g1][g2];
        int b1 = (solve(i+1, gcd(g1, nums[i]), g2 , nums)) % mod;
        int b2 = (solve(i+1, g1, gcd(g2, nums[i]) , nums)) % mod;
        int skip = (solve(i+1, g1, g2 , nums)) % mod;
        long long sum = ((long long)b1 + b2 + skip) % mod;
        return dp[i][g1][g2] = sum;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp , -1, sizeof(dp));
        return solve(0 , 0 , 0 , nums);
    }
};