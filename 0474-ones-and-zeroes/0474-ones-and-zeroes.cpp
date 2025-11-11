class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) { 
        // Let me start with my approach intuition, which is coming in my eye after reading the problem. The problem looks simpler, but there are some loads of twist. If I'm talking about the root force, then going to optimization approach like there is a string I know I want to find a sub string sub strings are fine by the just using the two loops or the strings or the DP is also working in a sub, sub string o but what is the solution of that like how the things are done if I want to say that about optimize approach by taking the brute force into that if I say like taking the size of the strings and iterate to it, there is Eminem we wanna store the DP int and we wanna E*TRADE through the string and in the DP. We wanna add those elements or the strings which contains the M number of zeros and number of ones, and a large sub, we need a problem just with the twist of MNN1 and zero and that's it. We wanna return the size of the DP in last.
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
        for(auto s : strs){
            int zero = count(s.begin() , s.end() , '0');
            int one = s.length() - zero;
            for(int i=m; i>=zero; i--){
                for(int j = n; j>=one; j--){
                    dp[i][j] = max(dp[i][j] , 1 + dp[i-zero][j-one]);
                }
            }
        }
        return dp[m][n];
    }
};