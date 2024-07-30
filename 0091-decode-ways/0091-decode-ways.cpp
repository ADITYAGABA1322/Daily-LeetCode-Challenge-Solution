class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1 , 0);
        dp[0]  = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        for(int i=2; i<=s.size(); i++){
            int first = s[i-1] - '0';
            int second = (s[i-2] - '0')*10 + (s[i-1] - '0');
            if(first >= 1 && first <= 9) dp[i] += dp[i-1];
            if(second >=10 && second <= 26) dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};