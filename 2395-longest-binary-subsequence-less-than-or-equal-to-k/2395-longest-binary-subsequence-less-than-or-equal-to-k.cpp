class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        
        // Count total zeros
        int zeroCount = 0;
        for (char c : s) {
            if (c == '0') zeroCount++;
        }
        
        // Try to include ones from right to left
        long long value = 0;
        long long pow = 1;
        int oneCount = 0;
        
        for (int i = n - 1; i >= 0 && pow <= k; i--) {
            if (s[i] == '1') {
                if (value + pow <= k) {
                    value += pow;
                    oneCount++;
                }
                // Otherwise skip this one
            }
            pow <<= 1; // Move to next position
        }
        
        return zeroCount + oneCount;
    }
};