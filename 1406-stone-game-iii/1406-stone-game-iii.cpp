class Solution {
public:
    int dp[50001];
    string stoneGameIII(vector<int>& stoneValue) {
        fill(dp , dp + 50001 , INT_MAX);
        int ans =  solve(0 , stoneValue);
        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        return "Tie";
    }
    int solve(int i , vector<int>& stoneValue){
        int n = stoneValue.size() , ans = INT_MIN;
        if(i>=n) return 0;
        if(dp[i] != INT_MAX) return dp[i];
        if(i< n) ans =  max(ans , stoneValue[i] - solve(i+1 , stoneValue));
        if(i+1 < n) ans = max(ans , stoneValue[i] + stoneValue[i+1] - solve(i+2 , stoneValue));
        if(i+2 < n) ans =  max(ans , stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3,stoneValue));
        return dp[i] = ans;
    }
};