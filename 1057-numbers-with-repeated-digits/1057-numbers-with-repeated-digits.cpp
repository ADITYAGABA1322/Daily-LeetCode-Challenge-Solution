class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        // Special case for n < 10
        if (n < 10) return 0;
        
        string s = to_string(n);
        int len = s.size();
        
        // memo[pos][tight][mask][started]
        vector<vector<vector<vector<int>>>> memo(
            len, vector<vector<vector<int>>>(
                2, vector<vector<int>>(
                    1 << 10, vector<int>(2, -1)
                )
            )
        );
        
        function<int(int, bool, int, bool)> dp = [&](int pos, bool tight, int mask, bool started) -> int {
            // Base case: processed all digits
            if (pos == len) return started ? 1 : 0;
            
            // Return memoized result if available
            if (memo[pos][tight][mask][started] != -1) 
                return memo[pos][tight][mask][started];
            
            int count = 0;
            
            // If we haven't started placing digits yet, we can skip this position
            if (!started) {
                count += dp(pos + 1, false, mask, false);
            }
            
            // Determine the range of digits we can place
            int limit = tight ? (s[pos] - '0') : 9;
            int start = started ? 0 : 1;  // If not started, we can't place 0
            
            for (int digit = start; digit <= limit; digit++) {
                // Skip if this digit has already been used
                if ((mask & (1 << digit)) > 0) continue;
                
                // Update mask with the current digit
                int newMask = mask | (1 << digit);
                
                // Update tight flag for next position
                bool nextTight = tight && (digit == limit);
                
                // Recurse to next position
                count += dp(pos + 1, nextTight, newMask, true);
            }
            
            // Memoize and return
            return memo[pos][tight][mask][started] = count;
        };
        
        // Count numbers without any repeated digits
        int numbersWithoutRepeats = dp(0, true, 0, false);
        
        // The answer is all numbers minus those without repeats
        return n - numbersWithoutRepeats;
    }
};