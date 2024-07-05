// p -> * or . -> return base case -> recusrion -> 2d dp return false-> agar nhi ha
// if len -> p.len > s.len -> return false
// . -> ki wohi char jo s mai ha jaise ki a 
// and * mean zero precding lement -> b then return true
// dp[*][.] -> i j and s.len. , p .len store
// loops -> if else khttarnak 
// algo
// 1.) stroe len and create 2 d dp of sizes of s and p
// 2.) tabulation -> for loop se phele hume intialize dp ko 
// 3.) if dp[i][j] = "*" amd net else * . 

class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length() , n = p.length();
        boolean[][] dp = new boolean[m+1][n+1];
        dp[0][0] = true;
        for(int j=1; j<=n; j++){
            if(p.charAt(j-1) == '*') dp[0][j] = dp[0][j-2];
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p.charAt(j-1) == '.' || p.charAt(j-1) == s.charAt(i-1)){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p.charAt(j-1) == '*'){
                    dp[i][j] = dp[i][j-2];
                    if(p.charAt(j-2) == '.' || p.charAt(j-2) == s.charAt(i-1)){
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
}