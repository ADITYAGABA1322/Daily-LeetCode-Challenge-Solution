class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // If k is divisible by 2 or 5, no solution exists
        // (repunits are odd and don't end in 0 or 5)
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        
        int remainder = 0;
        
        // Try repunits of length 1, 2, 3, ...
        for (int length = 1; length <= k; length++) {
            // Build repunit incrementally using modular arithmetic
            // repunit = repunit * 10 + 1
            remainder = (remainder * 10 + 1) % k;
            
            if (remainder == 0) {
                return length;
            }
        }
        
        return -1;
    }
};