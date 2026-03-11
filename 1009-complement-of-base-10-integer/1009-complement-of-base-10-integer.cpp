class Solution {
public:
    int bitwiseComplement(int n) {
        int res = 0 , cnt = 0;
        if(n == 0) return 1;
        while(n>0){
            int r = n % 2;
            res =  res + (pow(2 , cnt) * !r);
            n /= 2;
            cnt++;
        }
        return res;
    }
};