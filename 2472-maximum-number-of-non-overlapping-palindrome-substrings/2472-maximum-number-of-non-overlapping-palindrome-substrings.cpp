class Solution {
public:
    int dp[2001];
    int solve(string& s , int&k , int i , vector<vector<bool>>& isPal){
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int best = solve(s , k , i+1 , isPal);
        // take a palindrome cnt atleast k size
        for(int j=i+k-1; j<s.size(); j++){
            if(isPal[i][j]){
                int take = 1+solve(s , k , j+1 , isPal);
                best = max(best , take);
            }
        }
        return dp[i] = best;
    }
    int maxPalindromes(string s, int k) {
        memset(dp , -1 , sizeof(dp));
        int n = s.size();
        vector<vector<bool>> isPal(n , vector<bool>(n , false));
        for(int len=1; len <= n; len++){
            for(int i=0; i+len<=n; i++){
                int j = i+len-1;
                if(len == 1) isPal[i][j] = true;
                else if(len == 2) isPal[i][j] = (s[i] == s[j]);
                else isPal[i][j] = (s[i] == s[j]) && isPal[i+1][j-1];
            }
        }
        return solve(s , k , 0, isPal);
    }
};