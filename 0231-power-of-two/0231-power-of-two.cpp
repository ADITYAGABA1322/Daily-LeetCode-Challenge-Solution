class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // Power of two should be positive
        return (n & (n - 1)) == 0; // Check if only one bit is set
    }
};
