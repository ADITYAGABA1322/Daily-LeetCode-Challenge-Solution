class Solution {
public:
    int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
    int gcdOfOddEvenSums(int n) { return gcd(n * n, n * (n + 1)); }
};