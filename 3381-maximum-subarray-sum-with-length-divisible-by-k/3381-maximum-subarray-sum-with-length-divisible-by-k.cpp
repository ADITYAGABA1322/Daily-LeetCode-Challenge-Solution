class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        long long maxSum = LLONG_MIN;
        
        // For each remainder when divided by k
        for (int rem = 0; rem < k; rem++) {
            long long minPrefix = LLONG_MAX;
            
            // Check all positions with same remainder
            for (int i = rem; i <= n; i += k) {
                if (minPrefix != LLONG_MAX) {
                    maxSum = max(maxSum, prefix[i] - minPrefix);
                }
                minPrefix = min(minPrefix, prefix[i]);
            }
        }
        
        return maxSum;
    }
};