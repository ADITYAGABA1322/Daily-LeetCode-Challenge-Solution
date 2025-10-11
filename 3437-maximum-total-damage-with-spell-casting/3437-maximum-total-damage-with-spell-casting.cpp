class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long dp[100001];
        sort(power.begin() , power.end());
        dp[0] = power[0];
        long long res = dp[0] , maxi = 0;
        for(int i=1 , j =0; i<power.size(); i++){
            if(power[i] == power[i-1]) dp[i] = dp[i-1] + power[i];
            else{
                while(power[i] - 2 > power[j]){
                    maxi = max(maxi , dp[j++]);
                }
                dp[i] = power[i] + maxi;
            }
            res = max(res , dp[i]);
        }
        return res;
    }
};