class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
        unsigned carry = (a&b)<<1;
        a = a^b;
        b = carry;
        }
        return a;
    }
};