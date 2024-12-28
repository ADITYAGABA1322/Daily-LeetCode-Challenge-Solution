#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; } ();
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> sum(n-k+1 , 0) , left(n-k+1 , 0) , right(n-k+1 , 0) , dp(4 , 0);
    //     for(int i=0; i<k; i++) sum[0] += nums[i];
    //     for(int i=k; i<n; i++){
    //        sum[i-k+1] = sum[i-k] - nums[i-k] + nums[i];
    //         left[i-k+1] = sum[i-k+1] > sum[left[i-k]] ? i-k+1 : left[i-k];
    //     }
    //     right[n-k] = n-k;
    //     for(int i=n-k-1 ; i>=0; i--){
    //         right[i] = sum[i] >= sum[right[i+1]] ? i : right[i+1];
    //     }
    //     for(int i=k; i<=n-2*k; i++){
    //         int curr = sum[left[i-k]] + sum[i] + sum[right[i+k]];
    //         if(curr > dp[0]) dp = {curr , left[i-k] , i , right[i+k]};
    //     }
    //     return {dp[1] , dp[2] , dp[3]};
    // }
    int n = nums.size();
    vector<int> sum(n-k+1 , 0) , left(n-k+1 , 0) , right(n-k+1 , 0) , dp(4 , 0);
    for(int i=0; i<k; i++) sum[0] += nums[i];
    for(int i=k; i<n; i++){
        sum[i-k+1] = sum[i-k] - nums[i-k] + nums[i];
        left[i-k+1] = sum[i-k+1] > sum[left[i-k]] ? i-k+1 : left[i-k];
    }
    right[n-k] = n-k;
    for(int i=n-k-1; i>=0; i--) {
        right[i] = sum[i] >= sum[right[i+1]] ? i : right[i+1];
    }
    for(int i=k; i<=n-2*k; i++){
        int curr = sum[left[i-k]] + sum[i] + sum[right[i+k]];
        if(curr >  dp[0]) dp = {curr , left[i-k] , i , right[i+k]};
    }
    return {dp[1] , dp[2] , dp[3]};
    }
};