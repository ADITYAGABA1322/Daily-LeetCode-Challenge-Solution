class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
    // Convert string numbers to integers (be careful about constraints)
    long long low = stoll(num1);
    long long high = stoll(num2);
    
    // Mod value as required
    const int MOD = 1e9 + 7;
    
    // Counter for valid numbers
    int count = 0;
    
    // Iterate through every number in the range
    for (long long i = low; i <= high; i++) {
        // Calculate digit sum for current number
        long long current = i;
        int digitSum = 0;
        
        while (current > 0) {
            digitSum += current % 10;
            current /= 10;
        }
        
        // Check if sum is in the required range
        if (digitSum >= min_sum && digitSum <= max_sum) {
            count = (count + 1) % MOD;
        }
    }
    
    return count;
}
};