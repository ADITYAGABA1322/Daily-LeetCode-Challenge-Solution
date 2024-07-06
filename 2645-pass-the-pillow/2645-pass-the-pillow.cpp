class Solution {
public:
    int passThePillow(int n, int time) {
        return n - abs(n-1-time % (2*n - 2));
    }
};