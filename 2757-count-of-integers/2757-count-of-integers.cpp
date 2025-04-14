class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        const int MOD = 1e9 + 7;
        
        // Function to count numbers <= upper with digit sum in range [min_sum, max_sum]
        auto countUpTo = [&](const string& upper, int min_sum, int max_sum) -> int {
            int n = upper.length();
            
            // memo[pos][tight][sum] = count of valid numbers
            vector<vector<vector<int>>> memo(n + 1, 
                                            vector<vector<int>>(2, 
                                                             vector<int>(401, -1)));
            
            function<int(int, bool, int)> dp = [&](int pos, bool tight, int sum) -> int {
                // Base case: processed all digits
                if (pos == n) {
                    return (sum >= min_sum && sum <= max_sum) ? 1 : 0;
                }
                
                // Return memoized result if available
                if (memo[pos][tight][sum] != -1) return memo[pos][tight][sum];
                
                int result = 0;
                // Maximum digit allowed at current position
                int limit = tight ? (upper[pos] - '0') : 9;
                
                // Try each valid digit
                for (int digit = 0; digit <= limit; digit++) {
                    // Skip if sum would exceed max_sum
                    if (sum + digit > max_sum) continue;
                    
                    // Next position's tight constraint
                    bool nextTight = tight && (digit == upper[pos] - '0');
                    
                    // Add count from recursive call
                    result = (result + dp(pos + 1, nextTight, sum + digit)) % MOD;
                }
                
                // Memoize and return
                return memo[pos][tight][sum] = result;
            };
            
            return dp(0, true, 0);
        };
        
        // Special case: handle numbers with leading zeros
        int low_sum = 0;
        for (char c : num1) {
            low_sum += c - '0';
        }
        
        // If num1 has digit sum in range, include it in count
        bool includeNum1 = (low_sum >= min_sum && low_sum <= max_sum) ? true : false;
        
        // Decrement num1 by 1 to get inclusive range [0, num2] - [0, num1-1]
        string num1Minus1 = decrementString(num1);
        
        // Count numbers in range by using DP for upper bounds
        int result = (countUpTo(num2, min_sum, max_sum) - countUpTo(num1Minus1, min_sum, max_sum)) % MOD;
        
        // Handle modular arithmetic for negative results
        if (result < 0) result += MOD;
        
        return result;
    }
    
private:
    // Helper function to decrement a string representation of a number
    string decrementString(const string& num) {
        string result = num;
        int i = result.length() - 1;
        
        while (i >= 0 && result[i] == '0') {
            result[i] = '9';
            i--;
        }
        
        if (i >= 0) {
            result[i]--;
        } else {
            return "0"; // If num was "1", return "0"
        }
        
        // Remove leading zeros
        if (result[0] == '0' && result.length() > 1) {
            return result.substr(1);
        }
        
        return result;
    }
};