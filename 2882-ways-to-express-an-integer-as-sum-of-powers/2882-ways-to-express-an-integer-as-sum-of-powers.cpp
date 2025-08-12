class Solution {
public:
    int numberOfWays(int n, int x) {
        // According to the problem statement, what I think we need to divide the numbers of the integer into the form of sum of powers of the different integers is equal to the N a simple case let's take a N divided take the wide loop and check it from the sun like if that kind of thing is equal to or not we want to go integer into string and not string for we want to check the integer and and after that we want to convert the number according to the ranges from the different type of number to the power is that equal to and how much operation is performed and return that result of the counter what is the approach what I thinking for this is the simple iteration and the another thing that I see that's the power its typical math problme type using dp i think but how 
        const int MOD = 1e9+7;
        vector<int> powers;
        for(int i=1; ; i++){
            long long power = 1;
            for(int j=0; j<x; j++){
                power *= i;
                if(power > n) break;
            }
            if(power > n) break;
            powers.push_back(power);
        }
        vector<vector<int>> dp(powers.size() + 1 , vector<int>(n+1 , 0));
        for(int i=0; i<=powers.size(); i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=powers.size(); i++){
            for(int sum = 0; sum <= n; sum++){
                dp[i][sum] = dp[i-1][sum];
                if(sum >= powers[i-1]){
                    dp[i][sum] = (dp[i][sum] + dp[i-1][sum - powers[i-1]]) % MOD;
                }
            }
        }
        return dp[powers.size()][n];
    }
};