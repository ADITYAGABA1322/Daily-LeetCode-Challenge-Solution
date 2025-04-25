class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long result = 0;
        
        // Map to store frequencies of prefix counts % modulo
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // Empty subarray
        
        int count = 0;  // Running count of elements satisfying the condition
        
        for (int i = 0; i < n; i++) {
            // Update count if current element satisfies the condition
            if (nums[i] % modulo == k) {
                count++;
            }
            
            // We need to find previous prefixes that would make current subarray interesting
            // If (count % modulo) - k = target (mod modulo), then count % modulo = (target + k) % modulo
            // So we look for prefixes with value (count - k) % modulo
            int target = ((count % modulo) - k + modulo) % modulo;
            
            // Add count of previous prefixes that make current subarrays interesting
            result += prefixCount[target];
            
            // Update prefix frequency
            prefixCount[count % modulo]++;
        }
        
        return result;
    }
};