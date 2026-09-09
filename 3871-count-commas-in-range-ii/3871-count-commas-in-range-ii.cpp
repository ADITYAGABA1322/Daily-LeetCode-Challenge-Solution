class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0 , curr = 1000;
        while(curr <= n){
            res += n - curr + 1;
            curr *= 1000;
        }
        return res;
    }
};