class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        
        // Count numbers without repeated digits
        int noRepeat = solve(0, 0, true, false, s);
        
        // Return numbers with at least one repeated digit
        return n - noRepeat;
    }
    
private:
    // dp[pos][mask][tight][started]
    int dp[10][1024][2][2];
    
    int solve(int pos, int mask, bool tight, bool started, const string& num) {
        // Reached the end
        if (pos == num.length()) {
            return started ? 1 : 0; // Count only if we've started a number
        }
        
        // Return cached result
        if (dp[pos][mask][tight][started] != -1) {
            return dp[pos][mask][tight][started];
        }
        
        int result = 0;
        
        // Option 1: Don't place any digit yet (only if we haven't started)
        if (!started) {
            result += solve(pos + 1, mask, false, false, num);
        }
        
        // Option 2: Place a digit
        int limit = tight ? (num[pos] - '0') : 9;
        
        // The possible digits we can place
        int start = started ? 0 : 1; // If we haven't started, we can't place 0
        
        for (int digit = start; digit <= limit; digit++) {
            // Skip if we've already used this digit
            if ((mask & (1 << digit)) != 0) continue;
            
            // Update the mask with the current digit
            int newMask = mask | (1 << digit);
            
            // Update tight flag
            bool newTight = tight && (digit == limit);
            
            // Recursively count numbers
            result += solve(pos + 1, newMask, newTight, true, num);
        }
        
        // Cache and return
        return dp[pos][mask][tight][started] = result;
    }
};