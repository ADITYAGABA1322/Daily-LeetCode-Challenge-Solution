class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;

        // Step 1: Iterate n-1 times (since we already initialized result with
        // x)
        while (--n) {
            // Step 2: Increment result and perform bitwise OR with x
            result = (result + 1) | x;
        }

        return result;
    }
};