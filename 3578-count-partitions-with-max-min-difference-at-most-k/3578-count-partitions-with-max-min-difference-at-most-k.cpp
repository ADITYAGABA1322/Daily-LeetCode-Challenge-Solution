class Solution {
public:
    // TLE 
    // int countPartitions(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> dp(n , -1);
    //     return solve(0 , nums , k , dp);
    // }

    // int solve(int i, vector<int>& nums, int k , vector<int>& dp) {
    //     int mod = 1e9+7;
    //     int n = nums.size();
    //     if (i == n) return 1;
    //     if(dp[i] != -1) return dp[i];

    //     long long ways = 0;
    //     int maxi = nums[i], mini = nums[i];

    //     for (int j = i; j < n; j++) {
    //         maxi = max(maxi, nums[j]);
    //         mini = min(mini, nums[j]);

    //         if (maxi - mini > k) break;
    //         ways = (ways + solve(j + 1, nums, k , dp))%mod;
    //     }

    //     dp[i] == (int)ways;
    //     return ways;
    // }
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1 ,  0);
        vector<long long> prefix(n+1 , 0);
        const int mod = 1e9+7;
        dp[0] = 1;
        prefix[0] = 1;
        multiset<int> cnt;
        for(int i=0 ,j = 0; i<n; i++){
            cnt.insert(nums[i]);
            while(j<=i && *cnt.rbegin() - *cnt.begin() > k){
                cnt.erase(cnt.find(nums[j]));
                j++;
            }
            if(j > 0){
                dp[i+1] = (prefix[i] - prefix[j-1] + mod) % mod;
            } else{
                dp[i+1] = prefix[i] % mod;
            }
            prefix[i+1] = (prefix[i] + dp[i+1]) % mod;
        }
        return dp[n];
    }
};