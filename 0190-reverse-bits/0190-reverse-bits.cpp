class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        if(n == 0) return 0;
        for(int i=1; i<=32; i++){
            res <<=1;
            res = res | (n&1);
            n>>=1;
        }
        return res;
    }
};