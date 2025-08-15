class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && ( n == 1 || (n%4 == 0 && isPowerOfFour(n/4)));
    }
};