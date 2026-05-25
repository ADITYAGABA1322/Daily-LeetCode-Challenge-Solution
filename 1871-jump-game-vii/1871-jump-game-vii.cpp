class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n, 0) ;
        dp[0] = 1;
        int cnt = 0;
        for(int j=1; j<=n-1; j++){
            if(j-minJump >= 0) cnt += dp[j-minJump];
            if(j-maxJump-1>=0) cnt -= dp[j-maxJump-1];
            if(cnt > 0 && s[j] == '0') dp[j] = 1;
        }
        return dp[n-1]>0;
    }
};