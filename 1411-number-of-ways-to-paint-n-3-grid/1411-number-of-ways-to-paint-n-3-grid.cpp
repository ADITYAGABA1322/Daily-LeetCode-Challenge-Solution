class Solution {
public:
     int MOD = 1e9+7;
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};
    vector<vector<int>> memo;
    
    int solve(int n , int prev){
        if(n == 0) return 1;
        if(memo[n][prev] != -1) return memo[n][prev];
        int res = 0; 
        string last = states[prev];
        for(int curr = 0; curr<12; curr++){
            if(curr == prev) continue;
            string currPat = states[curr];
            bool isConfilct = false;
            for(int col = 0; col<3; col++){
                if(currPat[col] == last[col]){
                    isConfilct = true;
                    break;
                }
            }
            if(!isConfilct) res = (res + solve(n-1 , curr)) % MOD;
        } 
        return memo[n][prev] = res;
    }

    int numOfWays(int n) {
        memo.resize(n , vector<int>(12 , -1));
        int res = 0;
        for(int i=0; i<12; i++){
            res = (res + solve(n-1 , i)) % MOD;
        }
        return res;
    }
};