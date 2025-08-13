class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && (n == 1 || (n%3 == 0 && isPowerOfThree(n/3)));
    }
};