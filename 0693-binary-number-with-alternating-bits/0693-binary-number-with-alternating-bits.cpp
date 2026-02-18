class Solution {
public:
    bool hasAlternatingBits(int n) {
        // Approach -1
        // bitset<32> b(n);
        // int bit = log2(n);
        // for(int i=0; i<=bit; i++){
        //     if(b[i] == b[i+1]) return false;
        // }
        // return true;
        // Approach -2
        // int curr = n%2;
        // n /= 2;
        // while(n>0){
        //     if(curr == n%2) return false;
        //     curr = n % 2;
        //     n /= 2;
        // }
        // return true;
        //  Approach -3
        unsigned int res = n ^ (n>>1);
        return  (res & (res+1)) == 0;
    }
};