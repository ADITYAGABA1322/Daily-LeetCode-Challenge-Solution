class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // gievn 0 indexed 2d int array ok questions points and brainpower ok / simple we want to perfomr the optimal approach to find the maimum points either greedy or dp in which we nned do using int skip and take we say and we move  next +2 quesiton if its is that way to check we want to pass the maxi points ok 
        int n = questions.size();
        vector<long> dp(n+1 , 0);
        for(int i=n-1; i>=0; i--){
            int points = questions[i][0];
            int brainPower = questions[i][1];
            int nextIdx = min(n , i+brainPower+1);
            dp[i] = max(points + dp[nextIdx] , dp[i+1]);
        }
        return dp[0];
    }
};